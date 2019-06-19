#include <bits/stdc++.h>
#include "input.hpp"

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9
//#define DEBUG
#ifdef DEBUG 
#define D(t, x) cerr << t << " : " << x << endl;
#else 
#define D(t, x)
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;

void dfs(vector<vi> &g, vi &state, vector<ll> &score, bool &failed, int u) {
    if(g[u].size() == 0) 
        failed = true;

    if(failed) return;
    if(state[u] == 2) return;

    D("at", u);
    state[u] = 1;
    for(int v : g[u]) {
        if(state[v] == 2) { // cross edge
            failed = true;
            D("crossedge", v);
            return;
        } else if(state[v] == 1) { // back edge
            score[u]++;
            score[v]--;
            D("backedge", v);
        } else if (state[v] == 0) {
            dfs(g, state, score, failed, v);
            score[u]++;
        }
    }
    state[u] = 2;
}

bool solve(vector<vi> &g, int start, int n) {
    vi state(n, 0);
    vector<ll> score(n, 0);
    bool failed = false;
    dfs(g, state, score, failed, start);

    D("score", score[start]);
    for(int i = 0; i < n; i++) {
        if(i == start) continue;
        D("score", score[i]);
        if(score[i] <= 0 || state[i] != 2)
            failed = true;
    }
    if(score[start] > 0) {
        failed = true;
    }

    return failed;
}

int main() {
    int n, m;
    input::scanint(&n);
    input::scanint(&m);

    vector<vi> g(n, vi());

    while(m--) {
        int from, to;
        input::scanint(&from);
        input::scanint(&to);
        g[from].emplace_back(to);
    }

    if(n == 1) {
        cout << "YES\n";
        return 0;
    }

    int failed = true;
    int start = 0;
    for(int i = 0; i < n; i++) {
        if(g[i].size() > g[start].size()) {
            start = i;
        }
    }
    failed = solve(g, start, n);
    D("failed", failed);

    if(failed)
        cout << "NO\n";
    else 
        cout << "YES\n";

    return 0;
}
