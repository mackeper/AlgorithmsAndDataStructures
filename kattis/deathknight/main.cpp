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

    int n, won = 0;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        bool lost = false;
        for(int i = 1; i < (int)str.size(); i++) {
            if(str[i-1] == 'C' && str[i] == 'D') {
                lost = true;
                break;
            }
        }
        if(!lost) {
            won++;
        }
    }

    cout << won << endl;

    return 0;
}
