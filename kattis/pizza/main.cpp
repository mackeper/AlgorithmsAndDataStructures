#include <bits/stdc++.h>
#include "input.hpp"
using namespace std;
typedef unsigned long long u64;

int main() {
    int tests;
    input::scanint(&tests);
    while(tests--) {
        int m, n;
        input::scanint(&m);
        input::scanint(&n);
        int town[m][n];
        u64 col_sum[m];
        u64 row_sum[n];
        fill(col_sum, col_sum + m, 0);
        fill(row_sum, row_sum + n, 0);
        for(int y = 0; y < n; y++) {
            for(int x = 0; x < m; x++) {
                input::scanint(&town[x][y]);
                row_sum[y] += town[x][y];
                col_sum[x] += town[x][y];
            }
        }

        u64 min_y_dist = 1e16;
        for(int r = 0; r < n; r++) {
            u64 tmp = 0;
            for(int y = 0; y < n; y++) {
                tmp += abs(r-y)*row_sum[y];
            }
            min_y_dist = min(min_y_dist, tmp);
        }
        u64 min_x_dist = 1e16;
        for(int c = 0; c < m; c++) {
            u64 tmp = 0;
            for(int x = 0; x < m; x++) {
                tmp += abs(c-x)*col_sum[x];
            }
            min_x_dist = min(min_x_dist, tmp);
        }

        cout << min_y_dist+min_x_dist << " blocks" << "\n";
    }

    return 0;
}
