namespace Tests
open NUnit.Framework

[<TestFixture>]
module test1 =
    [<SetUp>]
    let Setup () =
        ()

    [<Test>]
    let Test1 () =
        Assert.Pass()
