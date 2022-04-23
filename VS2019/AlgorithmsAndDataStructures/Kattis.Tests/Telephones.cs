using NUnit.Framework;

using Kattis;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace Kattis.Tests
{
    public class Telephones
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void Case1()
        {
            var inData = @"3 2
3 4 2 5
1 2 0 10
6 5 5 8
0 6
8 2
1 2
8 9 0 10
9 1
10 1";

            var outData = @"3
2
1
0
";
            var sb = new StringBuilder();
            var tr = new StringReader(inData);
            var tw = new StringWriter(sb);
            Kattis.Telephones.Run(tr, tw);
            Assert.AreEqual(outData, sb.ToString(), sb.ToString());
        }
    }
}