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

    map<char, pii> cards;
    cards['A'] = make_pair(11,11);
    cards['K'] = make_pair(4,4);
    cards['Q'] = make_pair(3,3);
    cards['J'] = make_pair(20,2);
    cards['T'] = make_pair(10,10);
    cards['9'] = make_pair(14,0);
    cards['8'] = make_pair(0,0);
    cards['7'] = make_pair(0,0);

    int n;
    char B;
    cin >> n >> B;
    
    int score = 0;
    rep(i, 0, n*4) {
        char x,y;
        cin >> x >> y;

        if(y != B) {
            score += cards[x].second;
        } else {
            score += cards[x].first;
        }
    }

    cout << score << endl;

    return 0;
}
