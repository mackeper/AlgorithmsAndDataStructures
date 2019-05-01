#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

//#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int rooms, booked;
    cin >> rooms >> booked;
    if(rooms == booked) {
        cout << "too late\n";
        return 0;
    }

    unordered_set<int> nono;
    for (int i = 0; i < booked; i++) {
        int a;
        cin >> a;
        nono.insert(a);
    }

    for(int i = 0; i < rooms; i++) {
        if(nono.find(i+1) == nono.end()) {
            cout << (i+1) << endl;
            return 0;
        }
    }

    return 0;
}
