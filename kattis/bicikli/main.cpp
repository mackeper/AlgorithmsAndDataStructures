#include <bits/stdc++.h>
#include "input.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool over = false;
ll mem[10001];

// state:
// 0 : unseen
// 1 : processing
// 2 : done
ll DFS2(const vector<vector<int>> &g, int node, int goal, vector<int> &state) {
    if(mem[node] != -1) { 
        return mem[node];
    }
    if(node == goal) {
        return 1;
    }

    state[node] = 1;
    ll res = 0;
    trav(u, g[node]) {
        if(state[u] == 0)  // unseen
            res += DFS2(g, u, goal, state);
        if(res > 0) {
            return 1;
        }
    }

    state[node] = 2;
    return res;
}

// state:
// 0 : unseen
// 1 : processing
// 2 : done
ll DFS(const vector<vector<int>> &g, int node, int goal, vector<int> &state) {
    if(mem[node] != -1) { 
        return mem[node];
    }
    if(node == goal) {
        trav(u, g[node]) {
            vector<int> state_copy(state.size(), 0);
            if(state[u] == 1) {
                return -1;
            }
            if(DFS2(g, u, goal, state_copy) != 0) {
                // test case 14 D:
                return -1;
            }
        }
        mem[node] = 1;
        return 1;
    }

    state[node] = 1;
    ll res = 0;
    trav(u, g[node]) {
        ll path = 0; 

        if(state[u] == 1) { // processing
            // Check if u can reach the goal.
            vector<int> state_copy(state.size(), 0);
            if(DFS2(g, u, goal, state_copy) > 0) {
                // Can reach the goal.
                return -1;
            } else {
                // no way to the goal.
                continue;
            }
        }
            
        if(state[u] == 0) { // unseen
            path = DFS(g, u, goal, state);
        } else {
            path = mem[u];
        }

        // if u belongs to a loop
        if(path == -1) {
            return -1;
        }
        
        res += path;

        // Only print the last 9 digits
        if(res >= 1000000000) {
            over = true;
            res -= 1000000000;
        }
    }

    state[node] = 2;
    mem[node] = res;
    return res;
}

int main() {
    memset(mem, -1, sizeof(mem));

    int n, m;
    input::scanint(&n);
    input::scanint(&m);
    vector<vector<int>> graph(n+1, vector<int>());
    int from, to;
    while(m--) {
        input::scanint(&from);
        input::scanint(&to);
        graph[from].push_back(to);
    }
    vector<int> state(n+1, 0);
    ll paths = DFS(graph, 1, 2, state);

    if(paths == -1) {
        cout << "inf\n";
    } else if(over) {
        cout << setfill('0') << setw(9) << paths << "\n";
    } else {
        cout << paths << "\n";
    }

    return 0;
}
