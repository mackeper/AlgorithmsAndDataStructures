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

ll mem[11];

ll fact(ll x) {
    if(mem[x] != 0) {
        return mem[x];
    }
    if(x == 1) {
        return 1;
    }

    ll res = x * fact(x-1);
    mem[x] = res;
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        cout << (fact(n)%10) << "\n";
    }

    return 0;
}
