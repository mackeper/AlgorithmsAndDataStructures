#include <bits/stdc++.h>
#include "graph.hpp"
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


    int tests;
    cin >> tests;

    while (tests--) {
        string dummy;
        int cols, rows;
        cin >> cols >> rows;
        getline(cin, dummy);
        popup::Graph<int> g(cols*rows+1);

        unordered_set<int> aliens;
        unordered_map<int, int> alien_index;
        int alien_count = 1;
        int start;

        char map[rows][cols];
        string line;
        int r = -1;
        int rows_tmp = rows;
        while (rows_tmp--) {
            getline(cin, line);
            stringstream ss(line);
            r++;
            char chr;
            int c = 0;
            while (c < (int)line.size()) {
                chr = line[c];
                map[r][c] = chr;
                if (r != 0 && chr != '#' && map[r-1][c] != '#') {
                    g.add_bi_edge(r*cols+c, ((r-1)*cols)+c, 1); 
                }

                if (c != 0 && chr != '#' && map[r][c-1] != '#') {
                    g.add_bi_edge(r*cols+c, r*cols+(c-1), 1); 
                }

                if(chr == 'S') {
                    start = r*cols+c;
                    alien_index[r*cols+c] = 0;
                }
                if(chr == 'A') {
                    aliens.insert(r*cols+c);
                    alien_index[r*cols+c] = alien_count++;
                }
                c++;
            }
        }

        vector<int> dist(rows*cols), came_from(rows*cols);
        popup::Graph<ll> g2(aliens.size()+1);

        // from start
        {
            queue<int> q;
            vector<bool> visited(rows*cols);

            q.push(start);
            visited[start] = true;
            came_from[start] = -1;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto &edge : g.list_[v]) {
                    int u = (int)edge.to();
                    if (!visited[u]) {
                        visited[u] = true;
                        q.push(u);
                        dist[u] = dist[v] + 1;
                        came_from[u] = v;
                        if(aliens.find(u) != aliens.end()) {
                            g2.add_bi_edge(
                                    alien_index[start], 
                                    alien_index[u], 
                                    dist[u]);
                        }
                    }
                }
            }
        }

        //from each alien
        for(int alien : aliens) {
            vector<int> dist_tmp(rows*cols);
            queue<int> q;
            vector<bool> visited(rows*cols);

            q.push(alien);
            visited[alien] = true;
            came_from[alien] = -1;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto &edge : g.list_[v]) {
                    int u = (int)edge.to();

                    if (!visited[u]) {
                        visited[u] = true;
                        q.push(u);
                        dist_tmp[u] = dist_tmp[v] + 1;
                        if(aliens.find(u) != aliens.end()) {
                            g2.add_edge(
                                    alien_index[alien], 
                                    alien_index[u], 
                                    dist_tmp[u]);
                        }
                    }
                }
            }
        }

        auto res = g2.kruskal();
        if(res) {
            cout << res->first << endl;
        } else {
            cerr << "no res\n";
        }

    }

    return 0;
}
