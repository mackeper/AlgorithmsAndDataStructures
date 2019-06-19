#include <bits/stdc++.h>
#include "modular.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long ll;
typedef unsigned __int128 u128;
typedef __int128 i128;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<size_t> a(n); // tooths
        vector<size_t> b(n); // b'th tooth should be at 0

        for(int i = 0; i < n; i++) {
            size_t ta, tb;
            cin >> ta >> tb;
            a[i] = ta;
            if(i%2 == 0) {
                b[i] = tb;
            } else {
                b[i] = (ta - tb);
            }

        }

        bool fail = false;
        for(int i = 0; i < n-1; i++) {
            auto res = 
                popup::general_chinese_rest_theorem
                    <__int128>(b[i], a[i], b[i+1], a[i+1]);
            if(res.has_value()) {
                a[i+1] = (size_t)res.value().second;
                b[i+1] = (size_t)res.value().first;
            } else {
                 cout << "Impossible\n";
                 fail = true;
                 break;
            }
        }
        if(!fail)
            cout << (size_t)b[n-1] << endl;     
    }
  return 0;
}
