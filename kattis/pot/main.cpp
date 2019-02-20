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
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    ll res = 0;
    ll p;
    while(n--) {
        cin >> p;
        res += (ll)pow(p/10, p%10);
    }
    cout << res << endl;

    return 0;
}
