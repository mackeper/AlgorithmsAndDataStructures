using System.Linq;
using DataStructures;
using Graph = DataStructures.Graph<int, int>;

namespace Algorithms;

public class Kruskal {
    public static Graph MST(Graph graph) {
        var mst = new Graph();
        var disjointSet = new DisjointSet(graph.Size + 1);

        var sortedEdges = graph.Edges.OrderBy(edge => edge.Weight).ToList();

        foreach (var edge in sortedEdges) {
            var root1 = disjointSet.Find(edge.Source);
            var root2 = disjointSet.Find(edge.Destination);

            if (root1 != root2) {
                mst.AddEdge(edge);
                disjointSet.Union(root1, root2);
            }
        }

        return mst;
    }
}
