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

int enter(int limit, int &current, int value) {
    if (current + value <= limit) {
        current = current + value;
        return 0;
    }
    return 1;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int l, x, s = 0, current = 0;
    cin >> l >> x;
    while (x--) {
        string event_type;
        int event_value;
        cin >> event_type >> event_value;
        if (event_type.compare("enter") == 0) 
            s += enter(l, current, event_value);
        if (event_type.compare("leave") == 0) 
            current -= event_value;
    }
    cout << s << endl;
    return 0;
}
