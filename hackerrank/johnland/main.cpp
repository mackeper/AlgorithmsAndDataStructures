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

    u64 n, m;
    cin >> n >> m;
    n++;
    vector<vector<pair<u64, u64>>> g(n);
    vector<vector<u64>> result(n, vector<u64>(n, -1));
    while(m--) {
        u64 u, v, cost;
        cin >> u >> v >> cost;
        cost = pow(2, cost);
        result[u][v] = cost;
        result[v][u] = cost;
    }

    for(u64 i = 0; i < n; i++) {
        result[i][i] = 0;
    }

    // floyd warshall
    for (u64 k = 0; k < n; k++) {
        for (u64 i = 0; i < n; i++) {
            for (u64 j = 0; j < n; j++) {
                if (result[i][k] != (u64)-1
                    && result[k][j] != (u64)-1)
                {
                    result[i][j] = std::min(
                        result[i][j],
                        result[i][k] + result[k][j]
                    );
                }
            }
        }
    }

    u64 sum = 0;
    for (u64 i = 0; i < n; i++) {
        for (u64 j = i+1; j < n; j++) {
            if (result[i][j] != (u64)-1)
            {
                sum += result[i][j];
            }
        }
    }

    stack<int> s;
    while(sum > 0) {
        s.push(sum%2);
        sum /= 2;
    }

    while(s.size() > 1){
        cout << s.top();
        s.pop();
    }

    cout << sum << endl;

    return 0;
}

