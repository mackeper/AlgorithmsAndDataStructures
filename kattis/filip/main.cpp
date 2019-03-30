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
    int fst, snd, fst2 = 0, snd2 = 0;
    cin >> fst >> snd;

    for(int i = 0; i < 3; i++) {
        fst2 = fst2 * 10 + fst % 10;
        snd2 = snd2 * 10 + snd % 10;
        fst /= 10;
        snd /= 10;
    }

    cout << (fst2 < snd2 ? snd2 : fst2) << endl;
    return 0;
}
