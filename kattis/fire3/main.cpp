#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef pair<int, int> pii;

struct Vertex {
    int x;
    int y;
    bool player;
    int dist;
};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //cin.exceptions(cin.failbit);

    int w, h;
    cin >> w >> h;
    vector<vector<char>> grid(w, vector<char>(h));
    deque<Vertex> q;
    for(int x = 0; x < w; x++) {
        for(int y = 0; y < h; y++) {
            cin >> grid[x][y];
            if(grid[x][y] == 'J') {
                q.push_front({x, y, true, 0});
            } else if(grid[x][y] == 'F') {
                q.push_back({x, y, false, 0});
            }
        }
    }

    unordered_set<int> visited;
    unordered_set<int> burnt;
    bool win = false;
    while(!q.empty() && !win) {
        auto state = q.front();
        q.pop_front();
        if(visited.find(state.x*1000+state.y) != visited.end()) continue;
        if(state.player 
                && burnt.find(state.x*1000+state.y) != burnt.end()) continue;
        visited.insert(state.x*1000+state.y);

        if(state.player && (state.x == 0 || state.x == w-1
                    || state.y == 0 || state.y == h-1)) {
            cout << (state.dist+1) << "\n";
            win = true;
            break;
        }

        if(state.x > 0 && grid[state.x-1][state.y] == '.') {
            q.push_back({state.x-1, state.y, state.player, state.dist+1});
            if(!state.player)
                burnt.insert((state.x-1)*1000+state.y);
        }
        if(state.x < w-1 && grid[state.x+1][state.y] == '.') {
            q.push_back({state.x+1, state.y, state.player, state.dist+1});
            if(!state.player)
                burnt.insert((state.x+1)*1000+state.y);
        }
        if(state.y > 0 && grid[state.x][state.y-1] == '.') {
            q.push_back({state.x, state.y-1, state.player, state.dist+1});
            if(!state.player)
                burnt.insert(state.x*1000+(state.y-1));
        }
        if(state.y < h-1 && grid[state.x][state.y+1] == '.') {
            q.push_back({state.x, state.y+1, state.player, state.dist+1});
            if(!state.player)
                burnt.insert(state.x*1000+(state.y+1));
        }
    }

    if(!win) {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
