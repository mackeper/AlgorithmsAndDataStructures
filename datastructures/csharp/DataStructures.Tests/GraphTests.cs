namespace DataStructures.Tests;

public class GraphTests {

    [Fact]
    public void AddEdge_Should_AddUnidinectionalEdge() {
        var graph = new Graph<int, int>();
        graph.AddEdge(1, 2, 3);
        Assert.Equal(1, graph.Size);
        Assert.Equal([new(1, 2, 3)], graph.GetNeighbors(1));
        Assert.Empty(graph.GetNeighbors(2));
    }

    [Fact]
    public void AddEdge_Should_AddEdge() {
        var graph = new Graph<int, int>();
        graph.AddEdge(new Edge<int, int>(1, 2, 3));
        Assert.Equal(1, graph.Size);
        Assert.Equal([new(1, 2, 3)], graph.GetNeighbors(1));
        Assert.Empty(graph.GetNeighbors(2));
    }

    [Fact]
    public void AddBidirectionalEdge_Should_AddBidirectionalEdge() {
        var graph = new Graph<int, int>();
        graph.AddBidirectionalEdge(1, 2, 3);
        Assert.Equal(2, graph.Size);
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
    public void Size_Should_ReturnZero_When_GraphIsEmpty() {
        var graph = new Graph<int, int>();
        Assert.Equal(0, graph.Size);
    }

    [Fact]
    public void Size_Should_ReturnNumberOfNodes() {
        var graph = new Graph<int, int>();
        graph.AddBidirectionalEdge(1, 2, 3);
        graph.AddBidirectionalEdge(1, 3, 4);
        Assert.Equal(3, graph.Size);
    }

    [Fact]
    public void Nodes_Should_ReturnEmptyList_When_GraphIsEmpty() {
        var graph = new Graph<int, int>();
        Assert.Empty(graph.Nodes);
    }

    [Fact]
    public void Nodes_Should_ReturnNodes() {
        var graph = new Graph<int, int>();
        graph.AddBidirectionalEdge(1, 2, 3);
        graph.AddBidirectionalEdge(1, 3, 4);
        Assert.Equal([1, 2, 3], graph.Nodes);
    }

    [Fact]
    public void Edges_Should_ReturnEmptyList_When_GraphIsEmpty() {
        var graph = new Graph<int, int>();
        Assert.Empty(graph.Edges);
    }

    [Fact]
    public void Edges_Should_ReturnEdges() {
        // Arrange
        var graph = new Graph<int, int>();
        graph.AddBidirectionalEdge(1, 2, 3);
        graph.AddBidirectionalEdge(1, 3, 4);

        // Act
        var edges = graph.Edges;

        // Assert
        Assert.Equal(4, edges.Count);
        Assert.Contains(new Edge<int, int>(1, 2, 3), edges);
        Assert.Contains(new Edge<int, int>(1, 3, 4), edges);
        Assert.Contains(new Edge<int, int>(2, 1, 3), edges);
        Assert.Contains(new Edge<int, int>(3, 1, 4), edges);
    }

}
