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
    
    int h, m;
    cin >> h >> m;

    int diff_h = (m / 45) >= 1 ? 0 : 1;
    int n_h = h - diff_h;
    int n_m = (60 + m - 45) % 60;

    printf("%d %d\n",((24+n_h)%24), n_m);

    return 0;
}
