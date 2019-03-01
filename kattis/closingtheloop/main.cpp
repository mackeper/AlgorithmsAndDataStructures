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

    int tests;
    cin >> tests;

    for (int i = 1; i <= tests; i++) {
        //set<int, greater<int>> blues;
        //set<int, greater<int>> reds;
        vector<int> reds;
        vector<int> blues;

        int ropes;
        cin >> ropes;
        while(ropes--) {
            int v;
            char c;
            cin >> v >> c;
            if(c == 'R')
                reds.push_back(v-1);
            else
                blues.push_back(v-1);
        }

        auto b_itr = blues.begin();
        auto r_itr = reds.begin();
        int length = 0;
        /*
        while(b_itr != blues.end() && r_itr != reds.end()) {
            length += (*b_itr++) + (*r_itr++);
        }
        */
        sort(reds.rbegin(), reds.rend());
        sort(blues.rbegin(), blues.rend());
        for(int x = 0; x < (int)min(reds.size(), blues.size()); x++) {
            length += reds[x] + blues[x];
        }

        cout << "Case #" << i << ": " << length << endl;
    }

    return 0;
}
