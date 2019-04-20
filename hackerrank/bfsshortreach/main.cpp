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

    int queries;
    cin >> queries;

    while(queries--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        while(m--) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int start;
        cin >> start;
        start--;
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> distance(n, -1);
        distance[start] = 0;
        q.push(start);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if(!visited[v]) {
                    distance[v] = distance[u] + 6;
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == start) continue;
            cout << distance[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
