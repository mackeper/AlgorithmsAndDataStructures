using System.Linq;
using DataStructures;

namespace Algorithms.Tests;

public class PrimTests {
    [Fact]
    public void MST() {
        // Arrange
        var graph = new Graph<int, int>();

        graph.AddEdge(0, 2, 10);
        graph.AddEdge(0, 1, 1);
        graph.AddEdge(1, 2, 1);

        // Act
        var mst = Prim.MST(graph);

        // Assert
        Assert.Equal(2, mst.Edges.Count);
        Assert.Equal(2, mst.Edges.Sum(edge => edge.Weight));
    }
}
