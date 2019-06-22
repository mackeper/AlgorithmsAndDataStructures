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

bool arith(vector<int> &s) {
    int diff = s[0] - s[1];
    for (int i = 2; i < s.size(); i++) {
        if (s[i-1] - s[i] != diff)
            return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> vals(n);
        for (auto &v : vals) {
            cin >> v;
        }

        if (arith(vals)) {
            cout << "arithmetic\n";
        } else {
            sort(vals.begin(), vals.end());
            if(arith(vals)) {
                cout << "permuted arithmetic\n";
            } else {
                cout << "non-arithmetic\n";
            }
        }
    }

    return 0;
}
