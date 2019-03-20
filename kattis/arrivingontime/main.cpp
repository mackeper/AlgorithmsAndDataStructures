#include <bits/stdc++.h>
#include "time_table_graph.hpp"
#include "binary_search.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    
    popup::Graph g(n);
    for(int i = 0; i < m; i++) {
        ll u, v, t_open, period, cost;
        cin >> u >> v >> t_open >> period >> cost;
        g.add_edge(u, v, t_open, period, cost);
    }

    if(g.dijkstra(0, 0, n-1) > s) {
        cout << "impossible\n";
        return 0;
    }

    int64_t res = alg::binary_search<int64_t>(0, s, s, [&](int64_t mid){
        return g.dijkstra(mid, 0, n-1);
    });
    cout << res << endl;
    return 0;
}
