#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

//#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;

class UnionFind {
    struct Subset {
        size_t parent;
        int rank;
    };
    Subset* contents_;
    size_t num_elements_;
    public:
    UnionFind(size_t num_elements) {
        contents_ = new Subset[num_elements];
        for (size_t i = 0; i < num_elements; i++) {
            contents_[i] = {i, 0};
        }
        num_elements_ = num_elements;
    }
    ~UnionFind() {
        delete contents_;
    }

    size_t size() {
        return num_elements_;
    }
    size_t find(size_t a) {
        if (contents_[a].parent != a) {
            contents_[a].parent = find(contents_[a].parent);
        }
        return contents_[a].parent;
    }

    void make_union(size_t a, size_t b) {
        size_t root_a = find(a);
        size_t root_b = find(b);
        if (contents_[root_a].rank < contents_[root_b].rank) {
            contents_[root_a].parent = root_b;
        } else if (contents_[root_a].rank > contents_[root_b].rank) {
            contents_[root_b].parent = root_a;
        } else {
            contents_[root_b].parent = root_a;
            contents_[root_a].rank += 1;
        }
    };
};

struct Edge {
    u64 from, to, weight;

};
bool operator<(const Edge a, const Edge b) {
    return a.weight < b.weight;
};

u64 kruskal(u64 num_nodes, vector<Edge> &edges) {
    std::sort(edges.begin(), edges.end());
    UnionFind uf(num_nodes+1);

    std::vector<Edge> result(edges.size());

    u64 mst_edge_count = 0;
    u64 cost = 0;
    for (auto& edge : edges) {
        if (uf.find(edge.from) != uf.find(edge.to)) {
            cost += edge.weight;
            uf.make_union(edge.from, edge.to);
            result[mst_edge_count++] = edge;
            if (mst_edge_count >= num_nodes -1) {
                break;
            }
        }
    }
    return cost;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    u64 n, m;
    cin >> n >> m;
    vector<Edge> edges;
    while(m--) {
        u64 u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }

    cout << kruskal(n, edges) << endl;

    return 0;
}
