#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

// current station, gas
ll mem[100][200];
vector<pll> gas_stations;
ll goal_dist;

ll trip(ll dist, ll gas, ll current_station) {
    if(gas < 0) 
        return numeric_limits<ll>::max();
    if(dist >= goal_dist) 
        return 0;
    if(mem[current_station][gas] != -1) 
        return mem[current_station][gas];


    ll res = numeric_limits<ll>::max();

    for(ll i = current_station+1; i < (ll)gas_stations.size(); i++) {
        if(dist+200 - gas_stations[i].first < 0)
            break;

        // Don't fill
        if(gas_stations[i].first >= dist && gas_stations[i].first <= dist+gas) {
            res = min(
                res,
                trip(gas_stations[i].first, gas-gas_stations[i].first, i)
                );
        }

        //Fill tank
        if(gas_stations[i].first >= dist && gas_stations[i].first <= dist+200) {
            ll t2 = trip(gas_stations[i].first, 200-(gas_stations[i].first-dist), i);
            //printf("fill max\n");
            if(t2 != numeric_limits<ll>::max()) {
                res = min(
                    res,
                    t2 + (200-gas)*gas_stations[current_station].second
                    );
            }
        }

        // fill enough to reach a station
        if(gas_stations[i].first >= dist 
                && gas_stations[i].first <= dist+200
                && (gas_stations[i].first - dist) - gas >= 0){
            ll gas_needed = (gas_stations[i].first - dist) - gas;
            ll t3 = trip(gas_stations[i].first, 0, i);
            if(t3 != numeric_limits<ll>::max()) {
                res = min(
                    res,
                    t3 + (gas_needed)*gas_stations[current_station].second
                    );
            }
        }
    }

    mem[current_station][gas] = res;
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //cin.exceptions(cin.failbit); // breaks while(cin>>dist...) ?

    memset(mem, -1, sizeof(mem));
    cin >> goal_dist;
    goal_dist += 100;

    ll dist, price;
    while(cin >> dist >> price) {
        gas_stations.emplace_back(make_pair(dist, price));
    }

    // Add the destionation as a gas station
    gas_stations.emplace_back(make_pair(goal_dist, 0));

    ll res = numeric_limits<ll>::max();
    
    // First station
    for(size_t i = 0; i < gas_stations.size(); i++) {
        if(100 - gas_stations[i].first < 0)
            break;

        res = min(
                res,
                trip(gas_stations[i].first, 100 - gas_stations[i].first, i)
                );
    }

    cout << ((res != numeric_limits<ll>::max()) ? to_string(res) : "Impossible") << "\n";
    return 0;
}
