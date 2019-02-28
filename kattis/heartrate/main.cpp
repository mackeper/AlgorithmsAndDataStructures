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

    while(tests--) {
        double b, p;
        cin >> b >> p;
        
        double res = (15/p)*4;
        cout << fixed << setprecision(4);
        cout << res*(b-1) << " " << res*b << " " << res*(b+1) << endl;
    }


    return 0;
}
