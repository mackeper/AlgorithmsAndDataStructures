namespace DataStructures {

    public record Edge<TNode, TWeight>(TNode from, TNode to, TWeight weight);

    public class Graph<TNode, TWeight> where TNode : IComparable<TNode> {

        private readonly Dictionary<TNode, List<Edge<TNode, TWeight>>> adjacencyList = [];

        public void AddEdge(TNode from, TNode to, TWeight weight) {
            if (!adjacencyList.ContainsKey(from))
                adjacencyList[from] = [];
            adjacencyList[from].Add(new Edge<TNode, TWeight>(from, to, weight));
        }

        public void AddBidirectionalEdge(TNode from, TNode to, TWeight weight) {
            AddEdge(from, to, weight);
            AddEdge(to, from, weight);
        }

        public List<Edge<TNode, TWeight>> GetNeighbors(TNode u) => !adjacencyList.TryGetValue(u, out var value) ? [] : value;

        public int GetSize() => adjacencyList.Count;
    }
}
