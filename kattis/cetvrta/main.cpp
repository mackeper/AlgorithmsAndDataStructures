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

    map<int, int> a;
    map<int, int> b;

    rep(i, 0, 3) {
        int x, y;
        cin >> x >> y;
        a[x]++;
        b[y]++;
    }

    int x, y;
    trav(v, a) {
        if(v.second == 1) {
            x = v.first;
        }
    }
    trav(v, b) {
        if(v.second == 1) {
            y = v.first;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}
