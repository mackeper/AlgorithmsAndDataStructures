#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

const unsigned long long MOD_PRIME = 922337220451ULL;
const unsigned long long ONE_PRIME = 16069ULL;
const unsigned long long INV_PRIME = 184249329619ULL;

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

    int n;
    cin >> n;

    vector<string> cats;
    unordered_map<string, vector<int>> m;
    
    for(int j = 0; j < n; j++) {
        string s;
        cin >> s;
        cats.push_back(s);
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
            string s2;
            cin >> s2;
            m[s2].push_back(j);
        }

    }

    vector<int> score(cats.size());
    string word;
    while(cin >> word) {
        if (m.find(word) != m.end()) {
            for (auto i : m[word])
                score[i]++;
        }
    }
    int best = 0;
    int best_i = 0;
    for (int i = 0; i < cats.size(); i++) {
        if (best < score[i]) {
            best = score[i];
            best_i = i;
        }
    }

    vector<string> out;
    for (int i = 0; i < cats.size(); i++) {
        if (score[i] == best) {
            out.push_back(cats[i]);
        }
    }
    sort(out.begin(), out.end());
    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << endl;
    }

    return 0;
}
