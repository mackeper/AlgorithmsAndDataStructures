using Graph = DataStructures.Graph<int, int>;
using PriorityQueue = DataStructures.PriorityQueue<int, int>;

namespace Algorithms;

public class Prims {
    public static Graph MST(Graph graph) {
        var mst = new Graph();
        var visited = new bool[graph.Size];

        mst.AddVertex(0);

        return mst;
    }
}
