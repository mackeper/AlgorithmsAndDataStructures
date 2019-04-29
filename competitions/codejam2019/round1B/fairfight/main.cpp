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


i64 fairfights(i64 K, i64 N, i64 L, i64 R, 
        vector<i64> &charles, vector<i64> &delilas, vector<vector<i64>> &mem) {

    if (mem[L][R] != -1) {
        return 0;
    }

    i64 res = 0, c_max = 0, d_max = 0;
    for (i64 i = L; i <= R; i++) {
        c_max = max(c_max, charles[i]);
        d_max = max(d_max, delilas[i]);
    }
    if (abs(c_max - d_max) <= K) {
        D("L: %lld R:%lld c: %lld d:%lld\n", L, R, c_max, d_max);
        res++;
    }

    for (i64 i = L+1; i <= R; i++) {
        res += fairfights(K, N, i, R, charles, delilas, mem);
    }
    for (i64 i = R-1; i >= L; i--) {
        res += fairfights(K, N, L, i, charles, delilas, mem);
    }

    mem[L][R] = res;
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //cin.exceptions(cin.failbit);
    
    i64 tests;
    cin >> tests;
    for (i64 t = 1; t <= tests; t++) {
        i64 N, K;
        cin >> N >> K;
        vector<i64> charles(N);
        vector<i64> delilas(N);
        vector<vector<i64>> mem(N, vector<i64>(N, -1));

        for (auto &s : charles) cin >> s;
        for (auto &s : delilas) cin >> s;
        auto res = fairfights(K, N, 0, N-1, charles, delilas, mem);
        printf("Case #%lld: %lld\n", t, res);

    }

    return 0;
}
