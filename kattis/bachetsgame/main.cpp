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

int mem[1000001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int stones;
    while(cin >> stones) {
        int tmp;
        cin >> tmp;
        vector<int> removable(tmp);
        for(auto &r : removable) {
            cin >> r;
        }

        fill(mem, mem+stones+1, -1);
        mem[0] = 1;
        for(int i = 0; i <= stones; i++) {
            for (auto r : removable) {
                if (i+r <= stones && mem[i+r] != 0)  {
                    mem[i+r] = 1 - mem[i];
                }
            }
        }

        if(mem[stones] == 0) 
            cout << "Stan wins\n";
        else
            cout << "Ollie wins\n";
    }

    return 0;
}
