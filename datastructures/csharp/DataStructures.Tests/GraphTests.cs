namespace DataStructures.Tests {
    public class GraphTests {

        [Fact]
        public void AddEdge_Should_AddUnidinectionalEdge() {
            var graph = new Graph<int, int>();
            graph.AddEdge(1, 2, 3);
            Assert.Equal(1, graph.GetSize());
            Assert.Equal([new(1, 2, 3)], graph.GetNeighbors(1));
            Assert.Empty(graph.GetNeighbors(2));
        }

        [Fact]
        public void AddBidirectionalEdge_Should_AddBidirectionalEdge() {
            var graph = new Graph<int, int>();
            graph.AddBidirectionalEdge(1, 2, 3);
            Assert.Equal(2, graph.GetSize());
            Assert.Equal([new(1, 2, 3)], graph.GetNeighbors(1));
            Assert.Equal([new(2, 1, 3)], graph.GetNeighbors(2));
        }

        [Fact]
        public void GetNeighbors_Should_ReturnEmptyList_When_NodeDoesNotExist() {
            var graph = new Graph<int, int>();
            Assert.Empty(graph.GetNeighbors(1));
        }

        [Fact]
        public void GetNeighbors_Should_ReturnNeighbors() {
            var graph = new Graph<int, int>();
            graph.AddBidirectionalEdge(1, 2, 3);
            graph.AddBidirectionalEdge(1, 3, 4);
            Assert.Equal([new(1, 2, 3), new(1, 3, 4)], graph.GetNeighbors(1));
        }

        [Fact]
        public void GetSize_Should_ReturnZero_When_GraphIsEmpty() {
            var graph = new Graph<int, int>();
            Assert.Equal(0, graph.GetSize());
        }

        [Fact]
        public void GetSize_Should_ReturnNumberOfNodes() {
            var graph = new Graph<int, int>();
            graph.AddBidirectionalEdge(1, 2, 3);
            graph.AddBidirectionalEdge(1, 3, 4);
            Assert.Equal(3, graph.GetSize());
        }

    }

}
