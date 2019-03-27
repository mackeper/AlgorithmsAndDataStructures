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

ll digitSum(ll value) {
    string s = to_string(value);
    ll res = 0;
    for(size_t i = 0; i < s.size(); i++) {
        res += (ll)(s[i]-'0');
    }
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll L, D, X;
    cin >> L >> D >> X;

    ll N = numeric_limits<ll>::max();
    ll M = -1;

    for(ll i = L; i <= D; i++) {
        //cerr << digitSum(i) << " " << X << endl;
        if(digitSum(i) == X) {
            N = min(N, i);    
            M = max(M, i);    
        }
    }

    cout << N << endl << M << endl;

    return 0;
}
