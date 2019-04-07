#include <bits/stdc++.h>
using namespace std;

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
    cin.sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    for(int i = 1; i <= tests; i++) {
        int N;
        string str;
        cin >> N >> str;
        stringstream ss;
        int x = 0, y = 0;
        for (char c : str) {
            int x0 = x, y0 = y;
            if(c == 'S') {
                ss << 'E';
            } else {
                ss << 'S';
            }
        }
        printf("Case #%d: %s\n", i, ss.str().c_str());
        
    }
    return 0;
}
