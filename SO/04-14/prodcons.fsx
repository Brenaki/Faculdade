// File: ProducerConsumer.fsx
open System
open System.Threading

let consumer =
    MailboxProcessor.Start(fun inbox ->
        let rec loop () = async {
            let! item = inbox.Receive()
            printfn "Consumer consumed: %d" item
            do! Async.Sleep(2000)
            return! loop()
        }
        loop())

let rec producer n =
    async {
        consumer.Post(n)
        printfn "Producer produced: %d" n
        do! Async.Sleep(1000)
        return! producer (n + 1)
    }

Async.Start(producer 0)
printfn "Press any key to exit..."
Console.ReadKey() |> ignore
