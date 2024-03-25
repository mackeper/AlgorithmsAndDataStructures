namespace DataStructures.Tests {
    public class DisjointSetTests {
        [Fact]
        public void Test1() {
            var ds = new DisjointSet(5);
            ds.Union(0, 1);
            ds.Union(1, 2);
            ds.Union(3, 4);
            Assert.Equal(ds.Find(0), ds.Find(1));
            Assert.Equal(ds.Find(1), ds.Find(2));
            Assert.Equal(ds.Find(3), ds.Find(4));
        }

        [Fact]
        public void Find_Should_ReturnSelfWhenThereIsNoUnions() {
            // Arrange
            var ds = new DisjointSet(3);

            // Act / Assert
            Assert.Equal(0, ds.Find(0));
            Assert.Equal(1, ds.Find(1));
            Assert.Equal(2, ds.Find(2));
        }

        [Fact]
        public void Find_Should_ReturnRootAfterUnion() {
            // Arrange
            var ds = new DisjointSet(3);
            ds.Union(0, 1);
            ds.Union(1, 2);

            // Act / Assert
            Assert.Equal(ds.Find(0), ds.Find(1));
            Assert.Equal(ds.Find(1), ds.Find(2));
            Assert.Equal(ds.Find(0), ds.Find(2));
        }
    }

}
