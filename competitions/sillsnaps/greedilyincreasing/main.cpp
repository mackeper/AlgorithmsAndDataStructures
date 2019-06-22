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
    int n;
    cin >> n;
    vector<int> s(n);
    for (auto &v : s) {
        cin >> v;
    }

    vector<int> r;
    r.push_back(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i] > r[r.size()-1])
            r.push_back(s[i]);
    }

    cout << r.size() << endl;
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }
    cout << endl;

    return 0;
}
