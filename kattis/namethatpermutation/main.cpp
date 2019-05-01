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

// int next_permutation(int x) {
//     int c = x & -x;
//     int r = x + c;
//     return ((x ^ r)/(4*c)) | r;
// }

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    while(cin >> n) {
        cin >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = i+1;
        }
    }

    return 0;
}
