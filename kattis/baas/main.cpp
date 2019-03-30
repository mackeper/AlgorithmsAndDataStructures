#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAX (u64)1e12

u64 getMax(
        u64 u, 
        vector<vector<u64>> &mem,
        vector<vector<u64>> &g, 
        vector<u64> &step, 
        u64 skip) {

    if(mem[u][skip] != MAX) {
        return mem[u][skip];
    }

    u64 cost = 0;
    for(u64 to : g[u]) {
        cost = max(cost, getMax(to, mem, g, step, skip));
    }
    if(u != skip) {
        cost += step[u];
    }

    mem[u][skip] = cost;
    return cost;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    u64 steps;
    cin >> steps;

    vector<u64> cost(steps);
    vector<vector<u64>> g(steps, vector<u64>());

    for(u64 i = 0; i< steps; i++) {
        cin >> cost[i];
    }

    for(u64 i = 0; i < steps; i++) {
        u64 dep;
        cin >> dep;
        for(u64 j = 0; j < dep; j++) {
            u64 a;
            cin >> a;
            a--;
            g[i].push_back(a);
        }
    }

    u64 total_cost = 1e16;
    vector<vector<u64>> mem(steps, vector<u64>(steps, MAX));
    for(u64 i = 0; i < steps; i++) {
        u64 worse_case = 0;
        for(u64 j = 0; j < steps; j++){
            worse_case = max(worse_case, getMax(j,mem, g, cost, i));
        }
        total_cost = min(worse_case, total_cost);
    }

    cout << total_cost << endl;


    return 0;
}
