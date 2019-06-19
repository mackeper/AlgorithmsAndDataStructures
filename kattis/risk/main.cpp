#include <bits/stdc++.h>
#include "flow_graph.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9
#define MAX 10e8

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    while(tests--) {
        int regions;
        cin >> regions;
        vector<pair<int, vector<int>>> g(
                regions, make_pair(
                    0, // armies
                    vector<int>()));
        vector<bool> borders_enemy(regions, false);

        // Get armies
        for (int i = 0; i < regions; i++) {
            cin >> g[i].first;
        }

        // Get borders
        for (int j = 0; j < regions; j++) {
            for (int i = 0; i < regions; i++) {
                char c;
                cin >> c;
                if (c == 'Y') {
                    g[i].second.push_back(j);

                    if(g[i].first == 0 && g[j].first > 0)
                        borders_enemy[j] = true;
                }
            }
        }

        int bordering = 0;
        popup::FlowGraph<int, int> graph(g.size()+2);
        for(int i = 0; i < (int)g.size(); i++) {
            for(int to : g[i].second) {
                if(g[to].first != 0) {
                    graph.add_edge(i, to, g[to].first-1, 0);
                }
            }
            if(borders_enemy[i]) {
                graph.add_edge(i, g.size()+1, 1, 0);
                bordering++;
            }
            graph.add_edge(g.size(), i, g[i].first-1, 0);
        }

    }

    return 0;
}
