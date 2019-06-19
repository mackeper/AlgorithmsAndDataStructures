#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9
#define MAX (int)10e8

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int num_rooms;
    while(cin >> num_rooms) {
        if(num_rooms == -1) break;

        vector<pair<int, vector<int>>> g(num_rooms);
        for(auto &r : g) {
            int energy;
            int num_exits;
            cin >> energy;
            cin >> num_exits;
            vector<int> exits;
            while (num_exits--) {
                int to;
                cin >> to;
                to--;
                exits.push_back(to);
            }
            r = make_pair(-energy, exits);
        }

        int source = 0;
        int sink = num_rooms-1;
        size_t n = (size_t)num_rooms;
        vector<int> d(n, MAX);
        vector<int> p(n, 0);
        d[source] = -100;
        bool improving = true;
        for (int itr = 0; improving || itr < (int)n-1; itr++) {
            improving = false;
            for(size_t j = 0; j < n; j++) {
                for(int to : g[j].second) {
                    if(d[j] == MAX) continue;
                    int new_dist = d[j] + g[to].first;
                    if(d[to] > new_dist && new_dist < 0) {
                        d[to] = new_dist;
                        p[to] = (int)j;
                        improving = true;
                        if(itr > (int)n) {
                            d[to] = -MAX;
                            g[to].first = MAX;
                        }
                    }
                }
            }
        }
        if(d[sink] == MAX) {
            cout << "hopeless\n";
        } else {
            cout << "winnable\n";
        }
    }

    return 0;
}
