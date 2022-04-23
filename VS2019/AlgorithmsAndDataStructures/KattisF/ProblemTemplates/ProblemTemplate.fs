namespace KattisF.ProblemTemplates
module ProblemTemplate = 
    let BuildTemplate name =
        seq {
            "namespace KattisF.Problems"
            ""
            $"module {name} ="
            "    open System"
            "    let Run input ="
            "        \"\""
            ""
            "    let private ParseConsole ="
            "        (fun _ -> Console.ReadLine())"
            "        |> Seq.initInfinite"
            "        |> Seq.takeWhile ((<>) null)"
            "        |> Run"
            "        |> printfn \"%s\""
            ""
            "    //[<EntryPoint>]"
            "    //let main args ="
            "    //    ParseConsole"
            "    //    0"
        }