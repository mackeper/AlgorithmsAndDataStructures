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
    cin.exceptions(cin.failbit);

    int p[6] = {1, 1, 2, 2, 2, 8};
    int x;
    for(int i = 0; i < 6; i++) {
        cin >> x;
        cout << (p[i] - x) << " ";
    }

    return 0;
}
