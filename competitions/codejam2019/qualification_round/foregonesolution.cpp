#include <bits/stdc++.h>
using namespace std;

#define DEBUG
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
        i64 N;
        cin >> N;
        i64 A = N, B = 0;
        i64 x = N;
        
        int cnt = 0;
        while(x > 0) {
            i64 y = x % 10;
            if(y == 4) {
                i64 r = 2*pow(10, cnt);
                A -= r;
                B += r;
            }
            x /= 10;
            cnt++;
        }
        printf("Case #%d: %lld %lld\n", i, A, B);
    }

    return 0;
}
