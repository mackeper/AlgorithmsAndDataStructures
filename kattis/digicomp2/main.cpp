#include <bits/stdc++.h>
#include "input.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Switch {
    bool L;
    int left;
    int right;
    ll balls_passes = 0;
};

int main() {
    ll balls;
    int switches;
    input::scanll(&balls);
    input::scanint(&switches);

    vector<Switch> s(switches+1);
    for(int i = 1; i < switches+1; i++) {
        char state = (char)getchar_unlocked();
        int left, right;
        getchar_unlocked();
        input::scanint(&left);
        input::scanint(&right);
        s[i] = Switch{state == 'L' ? true : false, left, right};
    }

    vector<bool> visited(switches+1, false);
    vector<int> toposort(switches+1);
    int count = 0;
    function<void(int)> dfs;
    dfs = [&count, &visited, &s, &toposort, &dfs](int u) {
        visited[u] = true;
        if (!visited[s[u].left])
            dfs(s[u].left);
        if (!visited[s[u].right])
            dfs(s[u].right);
        toposort[count++] = u;
    };

    // topo sort
    for (int i = 0; i < switches+1; i++) {
        if (!visited[i])
            dfs(i);
    }

    s[1].balls_passes = balls;

    for(auto it = toposort.rbegin(); it != toposort.rend(); it++) {
        int u = *it;
        if(u == 0) continue;

        ll b = s[u].balls_passes;
        bool odd = b%2 == 1;

        ll b_left   = b/2;
        ll b_right  = b/2;

        bool L = s[u].L;
        b_left  = odd && L     ? b_left+1  : b_left;
        b_right = odd && !L     ? b_right+1 : b_right;
        s[u].L   = odd               ? !L    : L;
        s[s[u].left].balls_passes += b_left;
        s[s[u].right].balls_passes += b_right;
        s[u].balls_passes = 0;
    }

    for(int i = 1; i < switches+1; i++) {
        printf("%c", (s[i].L ? 'L' : 'R'));
    }
    printf("\n");

    return 0;
}
