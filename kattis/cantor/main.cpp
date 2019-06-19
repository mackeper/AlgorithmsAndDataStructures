#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define tav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define EPS 10e-9

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);

  string str;
  while(cin >> str) {
    if(str == "END")
      break;
    double d = (atof(str.c_str()));
    bool member = true;
    if(abs(d - 1) < EPS) {
      printf("MEMBER\n");
      continue;
    }

    rep(i, 0, 16) {
      d *= 3;
      int t = (int)(d/3.0);
      //printf("%lf, %d\n", d, t);
      d -= t*3;
      if(t == 1) {
        member = false;
        break;
      }
    }
    if(member)
      printf("MEMBER\n");
    else 
      printf("NON-MEMBER\n");
  }

  return 0;
}
