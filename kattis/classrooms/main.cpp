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

bool interval_overlap(const pair<i64,i64> &a, const pair<i64, i64> &b) {
    return max(a.first, b.first) < min(a.second, b.second);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    i64 activies, num_classrooms;
    cin >> activies >> num_classrooms;

    vector<pair<i64, i64>> intervals(activies);
    vector<vector<pair<i64, i64>>> classrooms(num_classrooms);
    for (auto &a : intervals)
        cin >> a.first >> a.second;

    auto cmp = [](const pair<i64, i64> &a, const pair<i64, i64> &b) {
        // return a.first < b.first || (a.first == b.first && a.second < b.second);
        return abs(a.first - b.second) < abs(b.first - b.second);
    };
    auto cmp2 = [](const pair<i64, i64> &a, const pair<i64, i64> &b) {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    };

    sort(intervals.begin(), intervals.end(), cmp);

    i64 total_activies = 0;
    for (auto &a : intervals) {
        for (auto &c : classrooms) {
            // auto it = lower_bound(c.begin(), c.end(), a, cmp2);
            // cerr << "try: " << a.first << " " << a.second << endl;
            // if (it == c.end())
            //     cerr << "cend\n";
            // else {
            //     cerr << "cnotend " << it->first << " " << it->second << endl;
            // }
            // if ((it != c.end() && it->second <= a.first) || it == c.end()) {
            bool no_overlap = true;
            for(auto &i : c) {
                if (interval_overlap(i, a)) {
                    no_overlap = false;
                    break;
               }
            }
            if (no_overlap) {
                c.push_back(a);
                total_activies++;
                break;
            }
        }
    }

    cout << total_activies << "\n";

    return 0;
}
