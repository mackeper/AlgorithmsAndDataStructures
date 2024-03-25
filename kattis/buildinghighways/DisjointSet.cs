
namespace DataStructures {
    /** DisjointSet
     * (Also knowns as UnionFind
     */
    public class DisjointSet {

        private readonly int[] parent;

        public DisjointSet(int n) {
            parent = new int[n];
        }

        public int Find(int x) {
            if (parent[x] == x)
                return x;

            return Find(parent[x]);
        }

        public void Union(int x, int y) {
            parent[Find(x)] = Find(y);
        }
    }
}
