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

    int n;
    cin >> n;
    while(n--) {

        vector<int> s(4);
        vector<int> p(4);
        
        cin >> s[0] >> s[1] >> p[0] >> p[1] 
            >> s[2] >> s[3] >> p[2] >> p[3];
        bool won = false;

        int g = gcd(gcd(p[0], p[1]), gcd(p[2], p[3]));
        for(int i = 0; i < 4; i++) {
            s[i] %= g;
            p[i] = g;
        }

        int a = 0;
        for(; a < 1000 && !won; a++) {
            //a + c + s11 = 0
            //a + d + s21 = 0
            //b + c + s12 = 0
            //b + d + s22 = 0
            int c = g - (a + s[0])%g;
            int d = g - (a + s[2])%g;
            int b = g - (c + s[1])%g;
            if ((a + c +s[0])%g == 0 
                && (a + d + s[2])%g == 0
                && (b + c + s[1])%g == 0
                && (b + d + s[3])%g == 0){
                won = true;
                D("a:%d b:%d c:%d d:%d\n", a, b, c, d);
                break;
            }
        }
        
        if(won) {
            D("presses: %d\n", a);
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
