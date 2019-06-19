#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Point {
    ll x_, y_, z_;
    Point() : x_(0), y_(0), z_(0) {};
    Point(ll x, ll y, ll z) : x_(x), y_(y), z_(z) {};
};

struct WH {
    Point from_;
    Point to_;
    ll open_time_;
    ll cost_;
    WH() {}
    WH(Point from, Point to, ll t, ll c) :
        from_(from), to_(to), open_time_(t), cost_(c) {}
};

struct Edge {
    size_t from_;
    size_t to_;
    bool wh_;
    ll open_time_ = 0;
    ll cost_;
    bool open_ = true;
    Edge() {}
    Edge(size_t from, size_t to, ll cost) :
        from_(from), to_(to), wh_(false), cost_(cost) {};
    Edge(size_t from, size_t to, ll open_time, ll cost) :
        from_(from), to_(to), wh_(true), open_time_(open_time), cost_(cost) {};
};

ll bellman_ford(
        vector<vector<Edge>> &graph,
        size_t from,
        size_t to
        ) {
    size_t n = graph.size();
    vector<ll> d (n, numeric_limits<ll>::max());
    d[from] = 0;
    vector<ll> p(n);

    // Bellman-ford
    for (size_t i = 0; i < (n-1); i++) {
        for(size_t j = 0; j < n; j++) {
            for (auto &edge : graph[j]) {
                if (d[edge.from_] < numeric_limits<ll>::max()) {
                    ll cost = d[edge.from_] + edge.cost_;

                    // Wait for the wormhole to open
                    if(edge.wh_ && d[edge.from_] < edge.open_time_) {
                        cost += (edge.open_time_ - d[edge.from_]);       
                    }
                    
                    if(d[edge.to_] > cost) {
                        d[edge.to_] = cost;
                        p[edge.to_] = edge.from_;
                    }
                }
            }
        }
    }

    /*
     *  Run bellman-ford and set the distance to
     *  each wormhole in a negative cycle to the
     *  wormhole of minimum opening time + cost.
     */
    while(1) {
        // Find negative cycles
        size_t x = 1000;
        for(size_t j = 0; j < n; j++) {
            for (auto &edge : graph[j]) {
                if (d[edge.from_] < numeric_limits<ll>::max()) {
                    ll cost = d[edge.from_] + edge.cost_;

                    // Wait for the wormhole to open
                    if(edge.wh_ && d[edge.from_] < edge.open_time_) {
                        cost += (edge.open_time_ - d[edge.from_]);       
                    }

                    if(d[edge.to_] > cost) {
                        d[edge.to_] = cost;
                        p[edge.to_] = edge.from_;
                        x = edge.to_;
                    }
                }
            }
        }

        if(x != 1000) {
            size_t y = x;
            for(size_t i = 0; i < n; i++) {
                y = p[y];
            }

            vector<size_t> path;
            for(size_t cur = y; ; cur = p[cur]) {
                path.push_back(cur);
                if(cur == y && path.size() > 1) {
                    break;
                }
            }

            reverse(path.begin(), path.end());
            ll min_open = numeric_limits<ll>::max();
            for(size_t i = 1; i < path.size(); i++) {
                size_t j = i - 1;
                for(auto &e : graph[path[j]]) {
                    if(e.to_ != path[i] || !e.wh_) continue;
                    min_open = min(min_open, abs(e.open_time_));
                }
            }

            for(size_t i = 1; i < path.size(); i++) {
                size_t j = i - 1;
                for(auto &e : graph[path[j]]) {
                    if(e.to_ != path[i] || !e.wh_) continue;
                    if(d[e.to_] > -min_open + e.cost_)
                        d[e.to_] = -min_open + e.cost_;
                }
            }
        } else {
            break;
        }
    }
    return d[to];
}

inline ll dist(Point p1, Point p2) {
    return (ll)(ceil(sqrt(
                pow(p1.x_-p2.x_,2)+
                pow(p1.y_-p2.y_,2)+
                pow(p1.z_-p2.z_,2))));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;

    while(tests--) {
        int x, y, z;
        int x2, y2, z2;
        cin >> x >> y >> z;
        Point source(x, y, z);
        cin >> x >> y >> z;
        Point sink(x, y, z);

        int num_whs;
        cin >> num_whs;
        vector<WH> wormholes(num_whs);

        for(int i = 0; i < num_whs; i++) {
            cin >> x >> y >> z;
            cin >> x2 >> y2 >> z2;
            int t, c;
            cin >> t >> c;

            wormholes[i] = WH(Point(x,y,z), Point(x2,y2,z2), t, c);
        }

        size_t s = 0;
        size_t t = 1;
        vector<vector<Edge>> graph(num_whs*2+2);
        graph[s].emplace_back(Edge(s, t, dist(source, sink)));
        for(int i = 2; i < num_whs+2; i++) {
            Point from = wormholes[i-2].from_;
            Point to = wormholes[i-2].to_;
            ll cost = wormholes[i-2].cost_;
            ll open = wormholes[i-2].open_time_;
            size_t other_side = i+num_whs;
            graph[s].emplace_back(Edge(s,i, dist(source, from)));
            graph[i].emplace_back(Edge(i, other_side, open, cost));
            graph[other_side].emplace_back(Edge(other_side, t, dist(to, sink)));
            for(int j = 2; j < num_whs+2; j++) {
                Point other_from = wormholes[j-2].from_;
                graph[other_side].emplace_back(
                        Edge(other_side, j, dist(other_from, to)));
            }
        }

        cout << bellman_ford(graph, s, t) << "\n";
        
    }

    return 0;
}


