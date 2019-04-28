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

int current_case = 0;
bool find_path(
        int cy, 
        int cx, 
        int r, 
        int c, 
        vector<vector<bool>> &visited,
        int depth,
        vector<pair<int, int>> &res) {
    if (depth == r*c) {
        return true;
    }

    D("visit: %d %d depth: %d\n", cy, cx, depth);
    for (int y = 0; y < r; y++) {
        if (y == cy) continue;
        for (int x = 0; x < c; x++) {
            if (x == cx) continue;
            if (visited[y][x]) continue;
            if (abs(abs(y - cy) - abs(x - cx)) < EPS) continue;
            visited[y][x] = true;
            res[depth].first = y;
            res[depth].second = x;
            if(find_path(y, x, r, c, visited, depth+1, res)) {
                return true;
            }
            visited[y][x] = false;
        }
    }

    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    while(tests--) {
        current_case++;
        int r, c;
        cin >> r >> c;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        vector<pair<int, int>> res(r*c);
        bool found = false;
        for(int y = 0; y < r && !found; y++) {
            for(int x = 0; x < c && !found; x++) {
                visited[y][x] = true;
                res[0].first = y;
                res[0].second = x;
                if (find_path(y, x, r, c, visited, 1, res)) {
                    printf("Case #%d: POSSIBLE\n", current_case);
                    for(auto &p : res) {
                        printf("%d %d\n", p.first+1, p.second+1);
                    }
                    found = true;
                }
                visited[y][x] = false;
            }
        }
        if(!found) {
            printf("Case #%d: IMPOSSIBLE\n", current_case);
        }
    }


    return 0;
}

