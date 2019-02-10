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

    string str;
    cin >> str;
    rep(i, 0, sz(str)-1) {
        if(str[i] == 's' && str[i+1] == 's') {
            cout << "hiss\n";
            return 0;
        }
    }
    cout << "no hiss\n";

    return 0;
}
