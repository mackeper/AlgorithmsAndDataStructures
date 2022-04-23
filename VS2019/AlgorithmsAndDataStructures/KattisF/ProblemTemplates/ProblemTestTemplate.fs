namespace KattisF.ProblemTemplates

module ProblemTestTemplate = 
    open KattisF
    let private Template problemName =
        seq {
            "namespace KattisF.Tests.Problems"
            ""
            $"module {problemName} ="
            "    open NUnit.Framework"
            "    open KattisF.Problems"
            ""
            "    [<SetUp>]"
            "    let Setup () ="
            "        ()"
        }

    let private AddTestToTemplate current name problemName (input:string) (answer:string) =
        [
            ""
            "    [<Test>]"
            $"    let Test{name} () ="
            $"        let input = \"\"\"{input.Trim()}\"\"\""
            $"        let answer = \"\"\"{answer.Trim()}\"\"\""
            $"        Assert.AreEqual(answer.Trim(), ({problemName}.Run (input.Split '\\n' |> Seq.takeWhile ((<>) null))).Trim())"
        ] |> Seq.append current

    let rec private BuildTemplateHelper current problemName samples =
        match samples with
        | [] -> current
        | (p, a):: xs -> BuildTemplateHelper (AddTestToTemplate current p.Name problemName p.Input a.Output) problemName xs
    
    let BuildTemplate problemName samples = 
        BuildTemplateHelper (Template problemName) problemName samples