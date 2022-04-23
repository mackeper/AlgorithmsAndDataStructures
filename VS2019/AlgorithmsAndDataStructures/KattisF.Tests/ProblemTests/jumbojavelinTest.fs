namespace KattisF.Tests.Problems

module jumbojavelin =
    open NUnit.Framework
    open KattisF.Problems

    [<SetUp>]
    let Setup () =
        ()

    [<Test>]
    let Test01 () =
        let input = """4
21
34
18
9"""
        let answer = """79"""
        Assert.AreEqual(answer.Trim(), (jumbojavelin.Run (input.Split '\n' |> Seq.takeWhile ((<>) null))).Trim())

    [<Test>]
    let Test02 () =
        let input = """3
1
50
40"""
        let answer = """89"""
        Assert.AreEqual(answer.Trim(), (jumbojavelin.Run (input.Split '\n' |> Seq.takeWhile ((<>) null))).Trim())
