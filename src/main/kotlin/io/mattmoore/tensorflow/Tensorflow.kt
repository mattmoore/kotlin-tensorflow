package io.mattmoore.tensorflow

class Tensorflow {
    init {
      System.loadLibrary("tensorflow_c_api")
    }

    external fun hello(): String

    external fun version(): String
}
