namespace KattisF.Tests.Problems

module jobexpenses =
    open NUnit.Framework
    open KattisF.Problems

    [<SetUp>]
    let Setup () =
        ()

    [<Test>]
    let Test01 () =
        let input = """3
1 -2 3"""
        let answer = """2"""
        Assert.AreEqual(answer.Trim(), (jobexpenses.Run (input.Split '\n' |> Seq.takeWhile ((<>) null))).Trim())

    [<Test>]
    let Test02 () =
        let input = """5
129 44 394 253 147"""
        let answer = """0"""
        Assert.AreEqual(answer.Trim(), (jobexpenses.Run (input.Split '\n' |> Seq.takeWhile ((<>) null))).Trim())

    [<Test>]
    let Test03 () =
        let input = """10
-100 40000 -6500 -230 -18 34500 -450 13000 -100 5000"""
        let answer = """7398"""
        Assert.AreEqual(answer.Trim(), (jobexpenses.Run (input.Split '\n' |> Seq.takeWhile ((<>) null))).Trim())

    [<Test>]
    let Test04 () =
        let input = """0"""
        let answer = """0"""
        Assert.AreEqual(answer.Trim(), (jobexpenses.Run (input.Split '\n' |> Seq.takeWhile ((<>) null))).Trim())
