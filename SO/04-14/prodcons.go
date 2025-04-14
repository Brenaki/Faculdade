// producer_consumer.go
package main

import (
    "fmt"
    "math/rand"
    "time"
)

const bufferSize = 5

func producer(ch chan<- int) {
    for {
        item := rand.Intn(100)
        ch <- item
        fmt.Printf("Producer produced: %d\n", item)
        time.Sleep(time.Second)
    }
}

func consumer(ch <-chan int) {
    for {
        item := <-ch
        fmt.Printf("Consumer consumed: %d\n", item)
        time.Sleep(2 * time.Second)
    }
}

func main() {
    ch := make(chan int, bufferSize)
    go producer(ch)
    go consumer(ch)

    // Mantem o programa rodando indefinidamente.
    select {}
}
