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

    vector<int> abc;
    
    rep(i, 0, 3) {
        int a;
        cin >> a;
        abc.push_back(a);
    }

    sort(abc.begin(), abc.end());

    rep(i, 0, 3) {
        char a;
        cin >> a;
        cout << *(abc.begin()+(a-'A')) << " ";
    }
    cout << endl;

    return 0;
}
