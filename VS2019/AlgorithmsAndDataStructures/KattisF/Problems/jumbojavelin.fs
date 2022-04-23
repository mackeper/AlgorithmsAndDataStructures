namespace KattisF.Problems

module jumbojavelin =
    open System

    let Run (input) =
        let ints = input |> Seq.skip 1 |> Seq.map int |> Seq.toList
        let amount = ints.Length
        let sum = ints |> List.sum
        sprintf "%i" (sum - amount + 1)
    
    let private ParseConsole =
        (fun _ -> Console.ReadLine())
        |> Seq.initInfinite
        |> Seq.takeWhile ((<>) null)
        |> Run
        |> printfn "%s"
        
    // [<EntryPoint>]
    // let main args =
    //     ParseConsole
    //     0