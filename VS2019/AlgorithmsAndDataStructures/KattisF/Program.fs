namespace KattisF

module Program =
    open System.Net.Http
    open System.IO
    open System.IO.Compression

    let GetEntryContent (entry: ZipArchiveEntry) =
        use stream = entry.Open()
        use reader = new StreamReader(stream)
        reader.ReadToEnd()

    let GetKattisSamples problemName =
        task {
            let url = $"https://open.kattis.com/problems/{problemName}/file/statement/samples.zip"
            use client = new HttpClient()
            use! responseStream = client.GetStreamAsync(url)
            use zipFile = new ZipArchive(responseStream);
            let problems = zipFile.Entries |> Seq.filter (fun e -> e.Name.EndsWith(".in")) |> Seq.map (fun e -> {Problem.Name = (e.Name.Split '.')[0]; Input = GetEntryContent e})
            let answers = zipFile.Entries |> Seq.filter (fun e -> e.Name.EndsWith(".ans")) |> Seq.map (fun e -> {Answer.Name = (e.Name.Split '.')[0]; Output = GetEntryContent e})
            return Seq.map2 (fun p a -> p, a: Sample) problems answers |> Seq.toList
        }
    

    let CreateFiles problemName samples =
        let pathProblems = @"D:\Documents\Projects\AlgorithmsAndDataStructures\VS2019\AlgorithmsAndDataStructures\KattisF\Problems"
        let pathTests = @"D:\Documents\Projects\AlgorithmsAndDataStructures\VS2019\AlgorithmsAndDataStructures\KattisF.Tests\ProblemTests"
        Directory.CreateDirectory(pathProblems) |> ignore
        Directory.CreateDirectory(pathTests) |> ignore
        if not (File.Exists $@"{pathProblems}.\{problemName}.fs") then
            File.WriteAllLines($@"{pathProblems}.\{problemName}.fs", ProblemTemplates.ProblemTemplate.BuildTemplate problemName)
        if not (File.Exists $@"{pathTests}.\{problemName}.fs") then
            File.WriteAllLines($@"{pathTests}.\{problemName}Test.fs", ProblemTemplates.ProblemTestTemplate.BuildTemplate problemName samples)
        problemName

    [<EntryPoint>]
    let main args =
        let problemName = "jobexpenses"

        // let samples = GetKattisSamples problemName |> Async.AwaitTask |> Async.RunSynchronously
        // printfn "%A" samples

        ProblemList.problemNames
        |> Seq.map (fun p -> CreateFiles p (GetKattisSamples p |> Async.AwaitTask |> Async.RunSynchronously))
        |> Seq.iter (printfn "%s done")

        0