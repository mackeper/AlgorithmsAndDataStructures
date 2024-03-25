namespace DataStructures {
    /** DisjointSet (Also knowns as UnionFind) */
    public class DisjointSet(int n) {

        private readonly int[] parent = Enumerable.Range(0, n).ToArray();
        private readonly int[] rank = new int[n];

        public int Find(int x) {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        public void Union(int x, int y) {
            var px = Find(x);
            var py = Find(y);

            if (px == py)
                return;

            if (rank[px] > rank[py])
                parent[py] = px;
            else if (rank[px] < rank[py])
                parent[px] = py;
            else {
                rank[px]++;
                parent[py] = px;
            }
        }
    }
}
