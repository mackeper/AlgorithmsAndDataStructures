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

    string s1, s2;
    cin >> s1 >> s2;
    if(s1.length() >= s2.length())
        cout << "go\n";
    else
        cout << "no\n";

    return 0;
}