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

int main() {
    int n;
    bool f = true;
    while(cin >> n && n != 0) {
        if(!f)
            putchar('\n');
        else
            f = false;
        int max_r = 0;
        getchar();
        vector<vector<char>> fig(100, vector<char>(n, ' '));
        for (int c = n-1; c >= 0; c--) {
            for (int r = 0; 1 ; r++) {
                fig[r][c] = (char)getchar();
                if (fig[r][c] == '|') {
                    fig[r][c] = '-';
                } else if (fig[r][c] == '-') {
                    fig[r][c] = '|';
                } else if (fig[r][c] == '\n') {
                    fig[r][c] = ' ';
                    break;
                }
                max_r = max(max_r, r);
            }
        }
        for (int r = 0; r < max_r+1; r++) {
            for (int c = 0; c < n; c++) {
                bool has_more = false;
                for(int i = c; i < n; i++) {
                    if(fig[r][i] != ' ') {
                        has_more = true;
                        break;
                    }
                }
                if(has_more) {
                    putchar(fig[r][c]);
                } else {
                    break;
                }
            }
            putchar('\n');
        }
    }

    return 0;
}
