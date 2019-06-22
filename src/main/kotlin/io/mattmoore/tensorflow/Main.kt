package io.mattmoore.tensorflow

fun main() {
  println(Tensorflow().hello())
  println(Tensorflow().version())
  val tensor = Tensor("Matt")
  println(tensor.name)
  // println(Tensor("Matt").name)
}
