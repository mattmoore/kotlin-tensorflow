ifeq ($(shell uname), Darwin)
	OS=darwin
	TARGET=libtensorflow_c_api.dylib
else
ifeq ($(shell uname), Linux)
	OS=linux
	TARGET=libtensorflow_c_api.so
endif
endif

all: prepare kotlin native

prepare:
	@if [ ! -d build/libs/tensorflow/shared ]; then \
		mkdir -p build/libs/tensorflow/shared; \
	fi

kotlin: prepare
	@echo "Compiling Kotlin code."
	@kotlinc-jvm -d build/libs/io.mattmoore.tensorflow.jar \
		-include-runtime \
		src/main/kotlin/io/mattmoore/tensorflow/*.kt \
		&& echo "Success."

native: prepare
	@echo "Building native code."
	@gcc -o build/libs/tensorflow/shared/$(TARGET) \
		src/tensorflow/c/tensorflow.c \
		-shared -fPIC \
		-I $(JAVA_HOME)/include \
		-I $(JAVA_HOME)/include/$(OS) \
		-ltensorflow \
		&& echo "Success."

run:
	@java \
		-cp build/libs/io.mattmoore.tensorflow.jar \
		-Djava.library.path=build/libs/tensorflow/shared \
		io.mattmoore.tensorflow.MainKt

clean:
	@if [ -e build/libs/ ]; then rm -rf build; fi
	@echo "Cleaned."
