package io.mattmoore.tensorflow

import kotlin.test.Test
import kotlin.test.assertTrue
import kotlin.test.assertEquals

class TensorflowTest {
    @Test
    fun testHello() {
        assertEquals(Tensorflow().hello(), "Hello World!")
        println(Tensorflow().hello())
    }

    @Test
    fun testVersion() {
        assertEquals(Tensorflow().version(), "v1")
        println(Tensorflow().version())
    }
}
