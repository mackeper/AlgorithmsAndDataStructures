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

    int tests;
    cin >> tests;

    while(tests--) {
        int students;
        cin >> students;
        vi grades(students);
        for(int i = 0; i < students; i++) {
            cin >> grades[i];
        }
        double avg = (double)accumulate(grades.begin(), grades.end(), 0)/(double)students;

        int above = 0;
        for(int i = 0; i < students; i++) {
            above = (double)grades[i] > avg ? above+1 : above;
        }

        cout << setprecision(3) << fixed << ((double)above/(double)students)*100 << "%\n";
        
    }

  return 0;
}
