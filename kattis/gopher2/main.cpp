#include <bits/stdc++.h>
#include "flow_graph.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<tuple<double, double, size_t>> vt;

inline bool isReachable(tuple<double, double, size_t> gopher, double x, double y, ll velocity, ll time) {
    double x_dist = get<0>(gopher)-x;
    double y_dist = get<1>(gopher)-y;
    double dist = x_dist*x_dist + y_dist*y_dist;
    double reachable_dist = (double)velocity*(double)time*(double)velocity*(double)time;
    return reachable_dist >= dist;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //cin.exceptions(cin.failbit);

    ll num_gophers, num_holes, time_limit, gopher_velocity;
    while(cin >> num_gophers >> num_holes >> time_limit >> gopher_velocity) {
        vt gophers(num_gophers);
        vt holes(num_holes);

        popup::FlowGraph<ll,ll> graph(num_holes+num_gophers+2);
        size_t source = 0;
        size_t sink = 1;
        size_t node_count = 2;

        for(size_t i = 0; i < gophers.size(); i++) {
            double x, y;
            cin >> x >> y;
            graph.add_edge(source, node_count, 1, 0);
            //printf("Add (%lu, %lu)\n", source, node_count);
            gophers[i] = make_tuple(x, y, node_count++);
        }

        for(size_t i = 0; i < holes.size(); i++) {
            double x, y;
            cin >> x >> y;

            graph.add_edge(node_count, sink, 1, 0);
            trav(gopher, gophers) {
                bool reachable = isReachable(gopher, x, y, gopher_velocity, time_limit);
                if(reachable) {
                    graph.add_edge(get<2>(gopher), node_count, 1, 0);
                }
            }

            node_count++;
        }

        cout << (num_gophers - graph.edmond_karp(source, sink)) << "\n";
    }
    return 0;
}
