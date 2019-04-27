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


int solve(int x, int y, vector<string> &grid) {

    if(x == (int)grid[0].size()) {
        return solve(0, y + 1, grid);
    }

    if (y == (int)grid.size()) {
        return 1;
    }


    if(grid[y][x] == '.') {
        bool possible = true;
        if (x > 0 && grid[y][x-1] == 'E') {
            possible = false;
        }
        else if (x < (int)grid[0].size()-1 && grid[y][x+1] == 'E') {
            possible = false;
        }
        else if (y < (int)grid.size()-1 && grid[y+1][x] == 'E') {
            possible = false;
        }
        else if (y > 0 && grid[y-1][x] == 'E') {
            possible = false;
        }

        if(possible) {
            grid[y][x] = 'E';
        }
    }

    return solve(x+1, y, grid);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(auto &s : grid) {
        for (int i = 0; i < m; i++) {
            char c;
            cin >> c;
            s.push_back(c);
        }
    }

    solve(0, 0, grid);

    for(auto &s : grid) {
        cout << s << endl;
    }


    return 0;
}
