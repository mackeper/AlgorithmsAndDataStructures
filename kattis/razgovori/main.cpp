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

  int num_detectors, houses;
  cin >> num_detectors >> houses;
  
  vector<pii> detectors(num_detectors); 
  trav(x, detectors) {
    int place;
    int calls;
    cin >> place >> calls;
    x = make_pair(place, calls);
  }

  sort(all(detectors));

  ll sum = 0;
  ll last_value = 0;
  trav(x, detectors) {
    if(last_value < x.second)
      sum += x.second - last_value;
    last_value = x.second;
  }

  cout << sum << endl;
    
  return 0;
}
