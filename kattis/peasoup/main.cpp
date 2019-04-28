#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

const unsigned long long MOD_PRIME = 922337220451ULL;
const unsigned long long ONE_PRIME = 16069ULL;
const unsigned long long INV_PRIME = 184249329619ULL;

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
    u64 h_pea = hash<string>{}("pea soup");
    u64 h_pan = hash<string>{}("pancakes");

    int r;
    cin >> r;
    while(r--) {
        int m;
        cin >> m;
        cin.ignore();
        string name;
        getline(cin, name);
        bool pea = false, pan = false;

        for(int i = 0; i < m; i++) {
            string food;
            getline(cin, food);
            u64 h_food = hash<string>{}(food);
            if(h_food == h_pea) pea = true;
            if(h_food == h_pan) pan = true;
            if(pan && pea) {
                cout << name << endl;
                return 0;
            }
        }

    }

    cout << "Anywhere is fine I guess" << endl;

    return 0;
}
