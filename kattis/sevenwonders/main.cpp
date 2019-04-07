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

    int cards[3] = {0};
    char c;
    while(cin >> c) {
        if(c == 'T') {
            cards[0]++;
        } else if(c == 'C') {
            cards[1]++;
        } else if(c == 'G') {
            cards[2]++;
        }
    }

    int sum = 0;
    sum += pow(cards[0], 2);
    sum += pow(cards[1], 2);
    sum += pow(cards[2], 2);
    sum += 7 * min(min(cards[0], cards[1]), cards[2]);
    cout << sum << endl;

    return 0;
}
