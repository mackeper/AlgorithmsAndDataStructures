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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    u64 tests;
    cin >> tests;
    while(tests--) {
        u64 n, m;
        cin >> n >> m;
        n++;
        vector<vector<pair<u64, u64>>> g(n);
        while(m--) {
            u64 u, v, cost;
            cin >> u >> v >> cost;
            g[u].push_back({v, cost});
            g[v].push_back({u, cost});
        }

        u64 start;
        cin >> start;
        
        priority_queue<pair<u64,u64>, vector<pair<u64,u64>>, greater<pair<u64, u64>>> pq;
        vector<bool> visited(n, false);
        vector<u64> distance(n, -1);
        distance[start] = 0;
        pq.push({0, start});
        while(!pq.empty()) {
            auto node = pq.top();
            u64 u = node.second;
            pq.pop();
            if (visited[u]) continue;
            visited[u] = true;

            for(auto e : g[u]) {
                u64 v = e.first;
                u64 cost = e.second;
                if(distance[v] > distance[u] + cost) {
                    distance[v] = distance[u] + cost;
                    pq.push({distance[v], v});
                }
            }
        }
        
        for (u64 i = 1; i < n; i++) {
            if (i == start) continue;
            if (distance[i] == (u64)-1)
                cout << "-1 ";
            else
                cout << distance[i] << " ";
        }
        cout << "\n";

    }

    return 0;
}
