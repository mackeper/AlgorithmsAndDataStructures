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
typedef vector<vector<int>> vvi;

int mem[100][8]; // m(turns) * outcomes(8)

int voting(int turn, int outcome, vvi &prefs) {
  //printf("turn: %d, outcome: %d\n", turn, outcome);
  if(turn >= (int)prefs.size()) {
    return outcome;
  }
  if(mem[turn][outcome] != -1) {
    return mem[turn][outcome];
  }

  int o1 = voting(turn+1, (outcome^4), prefs); // flip the first stone, xyy
  int o2 = voting(turn+1, (outcome^2), prefs); // flip the second stone, yxy
  int o3 = voting(turn+1, (outcome^1), prefs); // flip the thrid stone, yyx

  if(prefs[turn][o1] > prefs[turn][o2]) {
    if(prefs[turn][o3] > prefs[turn][o2]) {
      mem[turn][outcome] = o2;
    } else {
      mem[turn][outcome] = o3;
    }
  } else { 
      if(prefs[turn][o3] > prefs[turn][o1]) {
      mem[turn][outcome] = o1;
    } else {
      mem[turn][outcome] = o3;
    }
  }

  return mem[turn][outcome];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);

  int tests;
  cin >> tests;

  while(tests-- > 0) {
    memset(mem, -1, sizeof(mem));
    int voters;
    cin >> voters;
    vvi prefs(voters, vi(8));
    
    rep(i, 0, voters) {
      rep(j, 0, 8) {
        cin >> prefs[i][j];
      }
    }

    int outcome = voting(0, 0, prefs);

    cout << (outcome & 4 ? 'Y' : 'N');
    cout << (outcome & 2 ? 'Y' : 'N');
    cout << (outcome & 1 ? 'Y' : 'N');
    cout << "\n";
  }

  return 0;
}
