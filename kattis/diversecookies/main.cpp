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
    cin.sync_with_stdio(0);
    cin.tie(0);

    u64 friends, cookies[3];

    cin >> friends;
    cin >> cookies[0];
    cin >> cookies[1];
    cin >> cookies[2];

    sort(begin(cookies), end(cookies));

    u64 sum = 0;
    u64 caneat1 = friends;
    u64 caneat2 = 0;
    u64 caneat3 = 0;
    for(int round = 0; round < 10000; round++) {
        i64 a = min(caneat1, cookies[2]);   
        cookies[2] -=a;
        caneat1 -= a;
        caneat2 += a;
        caneat3 += a;
        sum += a;

        a = min(caneat2, cookies[1]);   
        cookies[1] -=a;
        caneat1 += a;
        caneat2 -= a;
        caneat3 += a;
        sum += a;

        a = min(caneat3, cookies[0]);   
        cookies[0] -=a;
        caneat1 += a;
        caneat2 += a;
        caneat3 -= a;
        sum += a;
    }
    
    cout << sum << endl;

    return 0;
}
