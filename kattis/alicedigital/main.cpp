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

    int t;
    cin >> t;
    while(t--) {
        
        ll n,m;
        cin >> n >> m;
        ll best = 0;
        ll sum = 0;
        ll m_c = 0;
        while(n--) {
            ll x;
            cin >> x;
            if(x == m && m_c == 0) {
                m_c = 1;
            } else if((x == m && m_c == 1) || x < m) {
                cerr << "best: " << best << " " << sum << endl;
                best = max(best, sum);
                sum = 0;
            }
            if(x >= m)
                sum += x;
        }
        if(m_c > 0)
            best = max(best, sum);
        cerr << "best: " << best << " " << sum << endl;
        cout << best << endl;

    }

    return 0;
}
