namespace KattisF.Problems

module jobexpenses =
    open System
    let Run (input:seq<string>) =
        match input |> Seq.head |> int with
        | 0 -> "0"
        | _ -> sprintf "%i" (
                input
                |> Seq.tail 
                |> Seq.head
                |> (fun a -> a.Split ' ')
                |> Seq.map int
                |> Seq.filter ((>) 0)
                |> Seq.sum
                |> abs
            )

    let private ParseConsole =
        (fun _ -> Console.ReadLine())
        |> Seq.initInfinite
        |> Seq.takeWhile ((<>) null)
        |> Run
        |> printfn "%s"

    // [<EntryPoint>]
    // let main args =
    //    ParseConsole
    //    0
