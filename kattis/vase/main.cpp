#include <bits/stdc++.h>
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

    int n;
    while(cin >> n) {
        vector<int> shapes(36, 0);
        vector<int> decorations(36, 0);
        vector<pii> vases(n);
        for (auto &v : vases) {
            cin >> v.first >> v.second;
            shapes[v.first]++;
            decorations[v.second]++;
        }
        int picked = 0;
    }

    return 0;
}
