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
            if(grid[x][y] == 'S') {
                q.push_front({x, y, true, 0});
            } else if(grid[x][y] == '*') {
                q.push_back({x, y, false, 0});
            }
        }
    }

    set<pii> visited;
    set<pii> burnt;


    bool win = false;
    while(!q.empty() && !win) {
        auto state = q.front();
        q.pop_front();
        if(visited.find({state.x, state.y}) != visited.end()) continue;
        if(state.player 
                && burnt.find({state.x, state.y}) != burnt.end()) continue;
        visited.insert({state.x, state.y});

        if(state.player && 
                   ((state.x > 0   && grid[state.x-1][state.y] == 'D') 
                 || (state.x < w-1 && grid[state.x+1][state.y] == 'D')   
                 || (state.y > 0   && grid[state.x][state.y-1] == 'D')
                 || (state.y < h-1 && grid[state.x][state.y+1] == 'D'))) {
            cout << (state.dist+1) << "\n";
            win = true;
            break;
        }

        if(state.x > 0 && grid[state.x-1][state.y] == '.') {
            q.push_back({state.x-1, state.y, state.player, state.dist+1});
            if(!state.player)
                burnt.insert({state.x-1, state.y});
            D("Burnt: %d %d\n", state.x-1, state.y);
        }
        if(state.x < w-1 && grid[state.x+1][state.y] == '.') {
            q.push_back({state.x+1, state.y, state.player, state.dist+1});
            if(!state.player)
                burnt.insert({state.x+1, state.y});
            D("Burnt: %d %d\n", state.x+1, state.y);
        }
        if(state.y > 0 && grid[state.x][state.y-1] == '.') {
            q.push_back({state.x, state.y-1, state.player, state.dist+1});
            if(!state.player)
                burnt.insert({state.x, state.y-1});
            D("Burnt: %d %d\n", state.x, state.y-1);
        }
        if(state.y < h-1 && grid[state.x][state.y+1] == '.') {
            q.push_back({state.x, state.y+1, state.player, state.dist+1});
            if(!state.player)
                burnt.insert({state.x, state.y+1});
            D("Burnt: %d %d\n", state.x, state.y+1);
        }
    }

    if(!win) {
        cout << "KAKTUS\n";
    }

    return 0;
}
