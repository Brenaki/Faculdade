// File: ProducerConsumer.swift
import Foundation

let bufferSize = 5
var buffer = [Int]()
let bufferLock = DispatchQueue(label: "bufferLock")
let empty = DispatchSemaphore(value: bufferSize)
let full = DispatchSemaphore(value: 0)

func producer() {
    DispatchQueue.global().async {
        for i in 0..<10 {
            empty.wait()
            bufferLock.sync {
                buffer.append(i)
                print("Producer produced: \(i)")
            }
            full.signal()
            sleep(1)
        }
    }
}

func consumer() {
    DispatchQueue.global().async {
        for _ in 0..<10 {
            full.wait()
            var item: Int = -1
            bufferLock.sync {
                if !buffer.isEmpty {
                    item = buffer.removeFirst()
                }
            }
            print("Consumer consumed: \(item)")
            empty.signal()
            sleep(2)
        }
    }
}

producer()
consumer()

dispatchMain() // Mantem a aplicacao rodando
