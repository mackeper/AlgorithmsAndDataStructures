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
    
    int tests;
    cin >> tests;
    while(tests--) {
        int w, h;
        cin >> w >> h;
        pii start;
        set<pii> on_fire;
        vector<vector<char>> grid(w, vector<char>(h));
        for(int y = 0; y < h; y++) {
            for(int x = 0; x < w; x++) {
                cin >> grid[x][y];
                if(grid[x][y] == '@') {
                    start = {x, y};
                } else if(grid[x][y] == '*') {
                    on_fire.insert({x, y});
                }
            }
        }

        queue<Vertex> q;
        set<pii> visited;
        set<pii> burnt;
        q.push({start.first, start.second, true, 0});
        for(auto itr = on_fire.begin(); itr != on_fire.end(); itr++) {
            q.push({itr->first, itr->second, false, 0});
        }


        bool win = false;
        while(!q.empty() && !win) {
            auto state = q.front();
            q.pop();
            if(visited.find({state.x, state.y}) != visited.end()) continue;
            if(state.player 
                && burnt.find({state.x, state.y}) != burnt.end()) continue;
            visited.insert({state.x, state.y});

            if(state.player && (state.x == 0 || state.x == w-1
                || state.y == 0 || state.y == h-1)) {
                cout << (state.dist+1) << "\n";
                win = true;
                break;
            }

            if(state.x > 0 && grid[state.x-1][state.y] == '.'
                  && visited.find({state.x-1, state.y}) == visited.end()) {
                q.push({state.x-1, state.y, state.player, state.dist+1});
                if(!state.player)
                    burnt.insert({state.x-1, state.y});
                D("Burnt: %d %d\n", state.x-1, state.y);
            }
            if(state.x < w-1 && grid[state.x+1][state.y] == '.'
                  && visited.find({state.x+1, state.y}) == visited.end()) {
                q.push({state.x+1, state.y, state.player, state.dist+1});
                if(!state.player)
                    burnt.insert({state.x+1, state.y});
                D("Burnt: %d %d\n", state.x+1, state.y);
            }
            if(state.y > 0 && grid[state.x][state.y-1] == '.'
                  && visited.find({state.x, state.y-1}) == visited.end()) {
                q.push({state.x, state.y-1, state.player, state.dist+1});
                if(!state.player)
                    burnt.insert({state.x, state.y-1});
                D("Burnt: %d %d\n", state.x, state.y-1);
            }
            if(state.y < h-1 && grid[state.x][state.y+1] == '.'
                  && visited.find({state.x, state.y+1}) == visited.end()) {
                q.push({state.x, state.y+1, state.player, state.dist+1});
                if(!state.player)
                    burnt.insert({state.x, state.y+1});
                D("Burnt: %d %d\n", state.x, state.y+1);
            }
        }

        if(!win) {
            cout << "IMPOSSIBLE\n";
        }

    }
    return 0;
}
