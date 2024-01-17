using NUnit.Framework;

namespace Util.Tests
{
    public class FenwickTreeTests
    {
        [SetUp]
        public void Setup()
        {
        }

        [Test]
        public void Empty()
        {
            var f = new FenwickTree(10);
            Assert.AreEqual(0, f.Sum(0));
        }

        [Test]
        public void OneValue()
        {
            var f = new FenwickTree(10);
            f.Update(5, 1);
            for (int i = 0; i < 10; i++)
                if(i <= 5)
                    Assert.AreEqual(0, f.Sum(i));
                else
                    Assert.AreEqual(1, f.Sum(i));
        }

        [Test]
        public void TwoValues()
        {
            var f = new FenwickTree(10);
            f.Update(5, 1);
            f.Update(6, 1);
            for (int i = 0; i < 10; i++)
                if (i <= 5)
                    Assert.AreEqual(0, f.Sum(i));
                else if (i <= 6)
                    Assert.AreEqual(1, f.Sum(i));
                else
                    Assert.AreEqual(2, f.Sum(i), $"index {i}");
        }

        [Test]
        public void PrefixSum()
        {
            var f = new FenwickTree(10);
            f.Update(0, 1);
            f.Update(1, 2);
            f.Update(2, 1);
            Assert.AreEqual(4, f.Sum(4));
            f.Update(0, -1);
            Assert.AreEqual(3, f.Sum(4));
        }

        [Test]
        public void Get()
        {
            var f = new FenwickTree(10);
            f.Update(0, 1);
            f.Update(1, 1);
            f.Update(2, 1);
            f.Update(3, 1);
            Assert.AreEqual(1, f.Sum(3) - f.Sum(2));
        }

        [Test]
        public void GetNegative()
        {
            var f = new FenwickTree(10);
            f.Update(0, 1);
            f.Update(1, 1);
            f.Update(2, 1);
            f.Update(2, -2);
            f.Update(3, 1);
            Assert.AreEqual(-1, f.Sum(3) - f.Sum(2));
        }

        [Test]
        public void GetMultiple()
        {
            var f = new FenwickTree(10);
            f.Update(2, 1);
            f.Update(3, 2);
            f.Update(4, 3);
            f.Update(2, 17);
            Assert.AreEqual(18, f.Sum(3) - f.Sum(2));
        }

        [Test]
        public void GetRange()
        {
            var f = new FenwickTree(10);
            f.Update(0, 1);
            f.Update(1, 1);
            f.Update(2, 1);
            f.Update(3, 1);
            f.Update(2, 3);
            Assert.AreEqual(4, f.SumRange(3, 3));
        }
    }
}