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

    int t;
    int test = 1;
    while (cin >> t && t != 0) {
        cout << "SET " << test++ << endl;
        int cnt = 0;
        stack<string> stk;
        for (int i = 0; i < t; i++) {
            string s;
            cin >> s;
            if (cnt % 2 == 0) {
                cout << s << endl;
            } else {
                stk.push(s);
            }
            cnt++;
        }
        while (!stk.empty()) {
            cout << stk.top() << endl;
            stk.pop();
        }
    }

    return 0;
}
