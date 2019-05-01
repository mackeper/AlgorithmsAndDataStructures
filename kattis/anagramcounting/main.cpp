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

string decimal_string(__int128 x) {
    vector<int> v;
    while (x > 0) {
        v.push_back(int(x%10));
        x = x/10;
    }
    string res = "";
    for(auto it = v.rbegin(); it != v.rend(); it++) {
        res += (char)((*it) + 48);
    }
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (cin >> s) {
        __int128 res = 1;

        unordered_map<char, int> unique;
        for(char c : s){
            if(unique.find(c) == unique.end())
                unique[c] = 1;
            else
                unique[c]++;
        }

        for(int i = 2; i <= (int)s.size(); i++)
            res *= i;

        for(auto it = unique.begin(); it != unique.end(); it++)
            res /= it->second;

        cout << decimal_string(res) << endl;
    }

    return 0;
}
