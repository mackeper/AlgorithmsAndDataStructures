#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long double total = 0;
    long double ws = 0;
    long double lc = 0;
    long double uc = 0;
    long double sy = 0;
    char c;
    while (cin >> c) {
        total++;
        if (c == '_') {
            ws++;
        } else if ('A' <= c && c <= 'Z') {
            uc++;
        } else if ('a' <= c && c <= 'z') {
            lc++;
        } else if (33 <= c && c <= 126) {
            sy++;
        }
    }

    cout << (ws > 0 ? ws/total : 0) << endl;
    cout << (lc > 0 ? lc/total : 0) << endl;
    cout << (uc > 0 ? uc/total : 0) << endl;
    cout << (sy > 0 ? sy/total : 0) << endl;

    return 0;
}
