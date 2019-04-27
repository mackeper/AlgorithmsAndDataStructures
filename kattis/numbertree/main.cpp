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

int get_node(int current, int p_idx, string &path) {
    D("c: %d\n", current);
    if(p_idx >= (int)path.size()) {
        return current;
    }

    if (path[p_idx] == 'L')
        return get_node(current*2+1, p_idx+1, path);
    else
        return get_node(current*2+2, p_idx+1, path);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int height;
    string path;
    cin >> height >> path;

    cout << ((int)(pow(2, height+1)) - 1 - get_node(0, 0, path)) << endl;

    return 0;
}
