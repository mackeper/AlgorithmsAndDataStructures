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

#define MAX (u64)1e9

void min_mud(vector<vector<u64>> &d, vector<vector<u64>> &mud) {
    vector<vector<bool>> visited(d.size(), vector<bool>(d[0].size(), false));
    auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) {
        return d[a.first][a.second] > d[b.first][b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for(int i = 0; i < (int)d.size(); i++) {
        pq.push({i, 0});
    }
    while(!pq.empty()) {
        auto [r, c] = pq.top();
        pq.pop();
        if(visited[r][c]) continue;
        visited[r][c] = true;

        if(r > 0 && d[r-1][c] > d[r][c]) {
            d[r-1][c] = max(d[r][c], mud[r-1][c]);
            pq.push({r-1, c});
        }
        if(r < (int)mud.size()-1 && d[r+1][c] > d[r][c]) {
            d[r+1][c] = max(d[r][c], mud[r+1][c]);
            pq.push({r+1, c});
        }
        if(c > 0 && d[r][c-1] > d[r][c]) {
            d[r][c-1] = max(d[r][c], mud[r][c-1]);
            pq.push({r, c-1});
        }
        if(c < (int)mud[r].size()-1 && d[r][c+1] > d[r][c]) {
            d[r][c+1] = max(d[r][c], mud[r][c+1]);
            pq.push({r, c+1});
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //cin.exceptions(cin.failbit);

    u64 rows, cols;
    cin >> rows >> cols;
    vector<vector<u64>> mud(rows, vector<u64>(cols));
    vector<vector<u64>> distance(rows, vector<u64>(cols, MAX));

    for(u64 r = 0; r < rows; r++) {
        for(u64 c = 0; c < cols; c++) {
            cin >> mud[r][c];
            if(c == 0) {
                distance[r][c] = mud[r][c];
            }
        }
    }

    for(u64 i = 0; i < rows; i++) {
    for(u64 j = 0; j < cols; j++) {
        D("%llu ", distance[i][j]);
    }
    D("\n");
    }
    min_mud(distance, mud);

    u64 least_muddy_path = MAX;
    for(u64 i = 0; i < rows; i++) {
        least_muddy_path = min(least_muddy_path, distance[i][cols-1]);
    }

    for(u64 i = 0; i < rows; i++) {
    for(u64 j = 0; j < cols; j++) {
        D("%llu ", distance[i][j]);
    }
    D("\n");
    }
    cout << least_muddy_path << endl;

    return 0;
}
