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

    ll tests;
    cin >> tests;

    while(tests--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        
        string res = "";
        for(size_t i = 0; i < s1.size(); i++) {
            if(s1[i] == s2[i])
                res += ".";
            else
                res += "*";
        }
        cout << s1 << endl;
        cout << s2 << endl;
        cout << res << endl;
    }

    return 0;
}
