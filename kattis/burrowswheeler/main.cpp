#include <bits/stdc++.h>
#include "suffix_array.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void print_str(string &s, const vector<size_t>& suffix, int a) {
    for(int i = a, j = 0; j < (int)s.size() && s[i] != '$'; i++, j++) {
        cerr << s[i%((int)s.size())];
    }
    cerr << "\n";
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(getline(cin, s)) {
        popup::CycleArray sa(s);
        vector<size_t> suff = sa.as_vector();
        for(int i = 0; i < (int)s.size(); i++) {
            //cout << suff[i] << endl; 
            cout << s[(suff[i]+(int)(s.size()-1))%(int)s.size()];
        }
        cout << "\n";
    }

    return 0;
}
