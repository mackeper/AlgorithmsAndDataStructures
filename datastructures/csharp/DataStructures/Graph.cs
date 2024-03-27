using System;
using System.Collections.Generic;
using System.Linq;

namespace DataStructures;

public record Edge<TNode, TWeight>(TNode Source, TNode Destination, TWeight Weight);

public class Graph<TNode, TWeight> where TNode : IComparable<TNode> {

    private readonly Dictionary<TNode, List<Edge<TNode, TWeight>>> adjacencyList = [];

    public void AddEdge(TNode source, TNode destination, TWeight weight) {
        if (!adjacencyList.ContainsKey(source))
            adjacencyList[source] = [];
        adjacencyList[source].Add(new Edge<TNode, TWeight>(source, destination, weight));
    }

    public void AddEdge(Edge<TNode, TWeight> edge) {
        if (!adjacencyList.ContainsKey(edge.Source))
            adjacencyList[edge.Source] = [];
        adjacencyList[edge.Source].Add(edge);
    }


    public void AddNode(TNode node) {
        if (!adjacencyList.ContainsKey(node))
            adjacencyList[node] = [];
    }

    public void AddBidirectionalEdge(TNode source, TNode destination, TWeight weight) {
        AddEdge(source, destination, weight);
        AddEdge(destination, source, weight);
    }

    public List<Edge<TNode, TWeight>> GetNeighbors(TNode u) => !adjacencyList.TryGetValue(u, out var value) ? [] : value;

    public int Size => adjacencyList.Count;

    public List<TNode> Nodes => [.. adjacencyList.Keys];

    public List<Edge<TNode, TWeight>> Edges => adjacencyList.Values.SelectMany(x => x).ToList();

}
