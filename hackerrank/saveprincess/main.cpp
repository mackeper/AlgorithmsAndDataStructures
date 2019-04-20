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

    int px, py;
    int mx, my;

    int n;
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            char c ;
            cin >> c;
            if (c == 'p') {
                px = x;
                py = y;
            } else if(c == 'm') {
                mx = x;
                my = y;
            }
        }
    }

    int x_diff = mx - px;
    int y_diff = my - py;

    string x_dir = x_diff > 0 ? "LEFT\n" : "RIGHT\n";
    string y_dir = y_diff > 0 ? "UP\n" : "DOWN\n";

    for(int i = 0; i < abs(x_diff); i++) {
        cout << x_dir;
    }
    for(int i = 0; i < abs(y_diff); i++) {
        cout << y_dir;
    }

    return 0;
}
