#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define tav(a, x) for(auto& a : x)
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

  int n;
  cin >> n;

  stack<char> st;
  while(n > 0) {
    if(n %2 == 0) {
      st.push('7');
    } else {
      st.push('4');
    }
    n = (n-1)/2;
  }

  while(!st.empty()) {
    cout << st.top();
    st.pop();
  }
  cout << "\n";

  return 0;
}
