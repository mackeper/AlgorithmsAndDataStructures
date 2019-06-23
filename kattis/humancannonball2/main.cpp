#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

#define PI 3.14159265359

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
    while(n--) {
        double v, o, x, h1, h2;
        cin >> v >> o >> x >> h1 >> h2;
        double t = x/(v*cos((o/180)*PI));
        double y = v*t*sin((o/180)*PI) - 9.81*t*t/2;
        if (h1+1 <= y && y <= h2-1)
            cout << "Safe\n";
        else
            cout << "Not Safe\n";
    }

    return 0;
}
