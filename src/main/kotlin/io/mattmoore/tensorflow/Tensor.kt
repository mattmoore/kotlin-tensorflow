package io.mattmoore.tensorflow

class Tensor(var name: String) {
  init {
    val t = tensor(name)
  }

  external fun tensor(name: String): Tensor
}
