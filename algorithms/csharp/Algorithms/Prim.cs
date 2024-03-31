using System.Collections.Generic;
using Graph = DataStructures.Graph<int, int>;
using PriorityQueue = System.Collections.Generic.PriorityQueue<DataStructures.Edge<int, int>, int>;

namespace Algorithms;

public class Prim {
    public static Graph MST(Graph graph) {
        var mst = new Graph();
        var visited = new HashSet<int>();

        var queue = new PriorityQueue();
        var firstVertex = graph.Vertices[0];
        visited.Add(firstVertex);
        foreach (var edge in graph.GetNeighbors(firstVertex)) {
            queue.Enqueue(edge, edge.Weight);
        }

        while (queue.Count > 0) {
            var edge = queue.Dequeue();

            if (visited.Contains(edge.Destination)) {
                continue;
            }

            mst.AddEdge(edge);
            visited.Add(edge.Destination);

            foreach (var vertex in visited) {
                graph.GetNeighbors(vertex).ForEach(e => {
                    if (!visited.Contains(e.Destination)) {
                        queue.Enqueue(e, e.Weight);
                    }
                });
            }
        }

        return mst;
    }
}
