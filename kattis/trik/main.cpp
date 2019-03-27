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
    int cups[3] = {1, 0, 0};

    string s;
    cin >> s;
    for (char c : s) {
        switch (c) {
            case 'A':
                swap(cups[0], cups[1]);
                break;
            case 'B':
                swap(cups[1], cups[2]);
                break;
            case 'C':
                swap(cups[0], cups[2]);
                break;
        }
    }
    for (size_t i = 0; i < 3; i++) {
        if(cups[i])
            cout << i+1 << endl;
    }

    return 0;
}
