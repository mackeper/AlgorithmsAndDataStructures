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

    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        u64 people, max_coord;
        cin >> people >> max_coord;

        vector<vector<i64>> grid(max_coord+1, vector<i64>(max_coord+1, 0));

        for (i64 i = 0; i < (i64)people; i++) {
            u64 x, y;
            char d;
            cin >> x >> y >> d;
            switch(d) {
            case 'N':
                for (i64 gy = y+1; gy < (i64)grid.size(); gy++) {
                    for (i64 gx = 0; gx <(i64) grid.size(); gx++) {
                        grid[gy][gx]++;
                    }
                }
                break;
            case 'S':
                for (i64 gy = y-1; gy >= 0; gy--) {
                    for (i64 gx = 0; gx < (i64)grid.size(); gx++) {
                        grid[gy][gx]++;
                    }
                }
                break;
            case 'W':
                for (i64 gx = x-1; gx >= 0; gx--) {
                    for (i64 gy = 0; gy < (i64)grid.size(); gy++) {
                        grid[gy][gx]++;
                    }
                }
                break;
            case 'E':
                for (i64 gx = x+1; gx < (i64)grid.size(); gx++) {
                    for (i64 gy = 0; gy < (i64)grid.size(); gy++) {
                        grid[gy][gx]++;
                    }
                }
                break;
            }
        }
        
        i64 max_x = 0, max_y = 0, max_p = 0;
        for (i64 gx = 0; gx < (i64)grid.size(); gx++) {
            for (i64 gy = 0; gy < (i64)grid.size(); gy++) {
                grid[gy][gx]++;
                if (grid[gy][gx] > max_p) {
                    max_x = gx;
                    max_y = gy;
                    max_p = grid[gy][gx];
                } else if (grid[gy][gx] == max_p
                        && max_x == gx
                        && max_y > gy) {
                    max_x = gx;
                    max_y = gy;
                    max_p = grid[gy][gx];
                } else if (grid[gy][gx] == max_p
                        && max_x > gx) {
                    max_x = gx;
                    max_y = gy;
                    max_p = grid[gy][gx];
                }
            }
        }

        printf("Case #%d: %lld %lld\n",t, max_x, max_y);

    }

    return 0;
}
