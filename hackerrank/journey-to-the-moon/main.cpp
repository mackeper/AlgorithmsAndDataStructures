#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long u64;

u64 dfs_num_nodes(u64 current, vector<bool> &visited, vector<vector<u64>> &g) {
    if(visited[current]) return 0;
    visited[current] = true;
    
    u64 cnt = 1;
    for (auto to : g[current]) {
        cnt += dfs_num_nodes(to, visited, g);
    }

    return cnt;
}

int main() {

    u64 n, p;
    cin >> n >> p;

    vector<vector<u64>> g(n, vector<u64>());

    while(p--) {
        u64 x, y;
        cin >> x >> y;
        if (x == y) continue;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<u64> component_sizes;
    vector<bool> visited(n, false);
    for(u64 i = 0; i < n; i++) {
        u64 res = dfs_num_nodes(i, visited, g);
        if(res != 0)
            component_sizes.push_back(res);
    }


    vector<u64> components_after(component_sizes.size());
    u64 tmp = 0;
    for(long long i = component_sizes.size()-1; i >= 0; i--) {
        components_after[i] = tmp;
        tmp += component_sizes[i];
    }

    u64 sum = 0;
    for (u64 i = 0; i < component_sizes.size(); i++) {
        sum += component_sizes[i]*components_after[i];
    }
    
    cout << sum << endl;
}
