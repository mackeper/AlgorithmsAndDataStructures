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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll num_nodes, num_edges, from, to, time_diff, num_george;
    cin >> num_nodes >> num_edges >> from >> to >> time_diff >> num_george;
    from--;
    to--;

    // Read georges path
    vector<ll> george_visits(num_george);
    ll x;
    for(size_t i = 0; i < (size_t)num_george; i++) {
        cin >> x;
		x--;
        george_visits[i] = x;
    }

    // Read streets
    vector<tuple<ll,ll,ll, ll>> streets(2*num_edges);
    for(size_t i = 0; i < 2*(size_t)num_edges; i+=2) {
        ll f, t, w;
        cin >> f >> t >> w;
        streets[i  ] = make_tuple(f-1, t-1, w, numeric_limits<ll>::max());
        streets[i+1] = make_tuple(t-1, f-1, w, numeric_limits<ll>::max());
    }

    // Add the time when George enters a street
    ll k = -time_diff;
    for(size_t i = 0; i < (size_t)num_george-1; i++) {
        if(num_george == 0)
            break;

		ll w = 0;
		for(size_t x = 0; x < streets.size(); x+=2) {
            auto e = streets[x];
        	auto f = get<0>(e);
        	auto t = get<1>(e);
			w = get<2>(e);
			if((george_visits[i] == f && george_visits[i+1] == t)
                || (george_visits[i] == t && george_visits[i+1] == f)) {
        		streets[x  ] = make_tuple(f, t, w, k);
        		streets[x+1] = make_tuple(t, f, w, k);
                break;
			}
		}
        k += w;
    }

    //djiktra
    vector<ll> distances(num_nodes, numeric_limits<ll>::max());
    vector<bool> visited(num_nodes, false);

    distances[from] = 0;
    rep(count, 0, num_nodes-1) {

        // find node with smallest distance
        ll u = numeric_limits<ll>::max();
        rep(x, 0, num_nodes) {
            if(!visited[x] && (u == numeric_limits<ll>::max() || distances[u] > distances[x])) {
                u = x;
            }
        }
        visited[u] = true;

        // Update neighbors
        for(auto &edge : streets) {
            if(get<0>(edge) != u)
                continue;
            auto v = get<1>(edge);

            ll time = distances[u] + get<2>(edge);
            if(get<3>(edge) != numeric_limits<ll>::max() 
				&&get<3>(edge) <= distances[u]
				&& distances[u] < get<3>(edge)+get<2>(edge)) {
                ll wait = get<3>(edge) + get<2>(edge) - distances[u];
				time += wait;
            }
            
            if(distances[v] > time) {
                distances[v] = time;
            }
        }
    }

    if(distances[to] == numeric_limits<ll>::max()) {
        cout << "fail!\n";
    } else {
        cout << distances[to] << "\n";
    }

    return 0;
}

