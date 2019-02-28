#include <bits/stdc++.h>
#include "flow_graph.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin, x.end()
#define sx(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    size_t num_tests;
    cin >> num_tests;

    rep(i, 0, num_tests) {
        size_t num_nodes, num_edges;
        cin >> num_nodes >> num_edges;
        popup::FlowGraph<int, int> g(num_nodes+num_edges+2);

        // in out
        vector<array<int,2>> degrees(num_nodes, {0,0});
        vector<pii> bi_edges;

        size_t s = num_nodes + num_edges;
        size_t t = num_nodes + num_edges + 1;

        int one_way_count = 0;
        rep(e, 0, num_edges) {
            size_t from, to, one_way;
            cin >> from >> to >> one_way;
            from--;
            to--;
            if (one_way) {
                degrees[from][1] += 1;
                degrees[to][0] += 1;
                one_way_count++;
            } else {
                bi_edges.push_back(make_pair(from, to));
            }
        }

        if(one_way_count == 0) {
            auto e = bi_edges[0];
            degrees[e.first][1] += 1;
            degrees[e.second][0] += 1;
        }

        bool first = true;
        size_t new_nodes = 0;
        for (auto& e : bi_edges) {
            if(one_way_count == 0 && first) {
                first = false;
                continue;
            }
            auto a = e.first;
            auto b = e.second;

            g.add_edge(num_nodes+new_nodes, a, 1, 0);
            g.add_edge(num_nodes+new_nodes, b, 1, 0);
            g.add_edge(s, num_nodes+new_nodes, 1, 0);
        }

        int needed_flow = 0;
        rep(v, 0, num_nodes) {
            int diff = abs(degrees[v][0] - degrees[v][1]);
            g.add_edge(v, t, diff, 0);
            needed_flow += diff;
        }

        auto res = g.edmond_karp(s, t);
        cerr << res << " " << needed_flow << endl;
        if(res >= needed_flow) {
            cout << "possible\n";
        } else {
            cout << "impossible\n";
        }

    }
}
