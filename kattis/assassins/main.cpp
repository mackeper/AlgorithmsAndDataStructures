#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

const unsigned long long MOD_PRIME = 922337220451ULL;
const unsigned long long ONE_PRIME = 16069ULL;
const unsigned long long INV_PRIME = 184249329619ULL;

//#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int assassins, att;
    cin >> assassins >> att;

    vector<long double> alive(pow(2, assassins), 0);
    alive[alive.size()-1] = 1;

    while (att--) {
        u64 a, b;
        long double p;
        cin >> a >> b >> p;
        a--;b--;
        for (u64 i = 0; i < alive.size(); i++) {
            if ((i & (1<<a)) && (i & (1<<b))) {
                alive[i & ~(1<<b)] += alive[i]*p;
                alive[i] *= (1-p);
            }
        }
    }
    for (u64 i = 0; i < (u64)assassins; i++) {
        long double res = 0;
        for (u64 j = 0; j < alive.size(); j++) {
            if ((j & (1<<i))) {
                res += alive[j];
            }
        }
        cout << res << "\n";
    }


    return 0;
}
