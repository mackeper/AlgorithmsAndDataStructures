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

    vector<int> heights(26);
    for (int i = 0; i < 26; i++) {
        cin >> heights[i];
    }

    string str;
    cin >> str;

    int max_height = 0;
    for(int i = 0; i < (int)str.size(); i++) {
        max_height = max(max_height, heights[str[i] - 'a']);
    }

    cout << max_height*str.size() << endl;

    return 0;
}
