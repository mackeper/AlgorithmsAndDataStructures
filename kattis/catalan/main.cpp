#include <bits/stdc++.h>
#include "big_integer.hpp"
#include "catalan.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

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

    int tests;
    cin >> tests;
    u64 max_len = 0;
    vector<u64> length(tests);
    for(auto &l : length) {
        cin >> l;
        max_len = max(l, max_len);
    }

    malg::CatalanNumbers<BigInteger> c(max_len+1);

    for(auto n : length) {
        BigInteger catalan = (c[n]);
        cout << catalan << "\n";
    }

    return 0;
}
