using System;
using System.Collections.Generic;
using System.Linq;

namespace DataStructures;

public record Edge<TVertex, TWeight>(TVertex Source, TVertex Destination, TWeight Weight);

public class Graph<TVertex, TWeight> where TVertex : IComparable<TVertex> {

    private readonly Dictionary<TVertex, List<Edge<TVertex, TWeight>>> adjacencyList = [];

    public void AddEdge(TVertex source, TVertex destination, TWeight weight) {
        if (!adjacencyList.ContainsKey(source))
            adjacencyList[source] = [];
        adjacencyList[source].Add(new Edge<TVertex, TWeight>(source, destination, weight));
    }

    public void AddEdge(Edge<TVertex, TWeight> edge) {
        if (!adjacencyList.ContainsKey(edge.Source))
            adjacencyList[edge.Source] = [];
        adjacencyList[edge.Source].Add(edge);
    }


    public void AddVertex(TVertex vertex) {
        if (!adjacencyList.ContainsKey(vertex))
            adjacencyList[vertex] = [];
    }

    public void AddBidirectionalEdge(TVertex source, TVertex destination, TWeight weight) {
        AddEdge(source, destination, weight);
        AddEdge(destination, source, weight);
    }

    public List<Edge<TVertex, TWeight>> GetNeighbors(TVertex vertex) => !adjacencyList.TryGetValue(vertex, out var value) ? [] : value;

    public int Size => adjacencyList.Count;

    public List<TVertex> Vertices => [.. adjacencyList.Keys];

    public List<Edge<TVertex, TWeight>> Edges => adjacencyList.Values.SelectMany(x => x).ToList();

}
