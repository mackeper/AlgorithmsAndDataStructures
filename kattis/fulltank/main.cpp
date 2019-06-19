#include <bits/stdc++.h>
#include "input.hpp"
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

struct Edge {
    int from;
    int to;
    int cost;
};

void cheapest_path(
        vector<vector<Edge>> &g, 
        vector<int> &prices,
        int source,
        int cap,
        int sink)
{
    vector<vector<bool>> visited(g.size()+1, vector<bool>(101, false));
    vector<vector<int>> cost(g.size()+1, vector<int>(101, (int)MAX));
    auto cmp = [&](const pair<int,int> &a, const pair<int,int> &b){
        return cost[a.first][a.second] > cost[b.first][b.second];
    };
    priority_queue<
        pair<int, int>, 
        vector<pair<int,int>>,
        decltype(cmp)> queue(cmp); //node, fuel
    cost[source][0] = 0;
    queue.push(make_pair(source, 0));

    while (!queue.empty()) {
        int u = queue.top().first;
        int u_fuel = queue.top().second;
        queue.pop();
        int u_cost = cost[u][u_fuel];
        if(visited[u][u_fuel]) continue;
        //visited[u][u_fuel] = true;
        
        for(auto &e : g[u]) {
            if(u_fuel - e.cost >= 0) {
                int v = e.to;
                if(cost[v][u_fuel-e.cost] > u_cost) {
                    cost[v][u_fuel-e.cost] = u_cost;
                    queue.push(make_pair(v, u_fuel-e.cost));}
            }
        }

        if(u_fuel+1 <= cap) {
            if(cost[u][u_fuel+1] > u_cost + prices[u]) {
                cost[u][u_fuel+1] = u_cost + prices[u];
                queue.push(make_pair(u, u_fuel+1));
            }
        };
    }

    int res = cost[sink][0];
    if(res == (int)MAX)
        printf("impossible\n");
    else
        printf("%d\n", res);

}


int main() {
    int cities, roads, queries;
    input::scanint(&cities);
    input::scanint(&roads);

    vector<vector<Edge>> g(cities, vector<Edge>());
    vector<int> prices(cities);

    rep (i, 0, cities) {
        input::scanint(&prices[i]);
    }

    int from, to, tcost;
    rep (i, 0, roads) {
        input::scanint(&from);
        input::scanint(&to);
        input::scanint(&tcost);
        g[from].emplace_back(Edge{from, to, tcost});
        g[to].emplace_back(Edge{to, from, tcost});
    }

    input::scanint(&queries);
    while (queries--) {
        int cap, source, sink;
        input::scanint(&cap);
        input::scanint(&source);
        input::scanint(&sink);
        cheapest_path(g, prices, source, cap, sink);

    }

    return 0;
}
