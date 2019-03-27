#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //cin.exceptions(cin.failbit);
    
    int n, m;
    cin >> n >> m;
    int res = m - n;
    string p = (int)abs(res) == 1 ? "piece" : "pieces";
    if(res > 0) {
        printf("Dr. Chaz will have %d %s of chicken left over!\n", (int)abs(res), p.c_str());
    } else {
        printf("Dr. Chaz needs %d more %s of chicken!\n", (int)abs(res), p.c_str());
    }
    return 0;
}
