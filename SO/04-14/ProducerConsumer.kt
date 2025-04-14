// File: ProducerConsumer.kt
import kotlinx.coroutines.*
import kotlinx.coroutines.channels.Channel

fun main() = runBlocking {
    val channel = Channel<Int>(5)

    launch {
        for (i in 0 until 10) {
            channel.send(i)
            println("Producer produced: $i")
            delay(1000L)
        }
        channel.close()
    }

    launch {
        for (item in channel) {
            println("Consumer consumed: $item")
            delay(2000L)
        }
    }
}
