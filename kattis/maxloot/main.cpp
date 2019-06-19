#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;
u64 n, capacity;

void all_subsets(
        u64 c, u64 c_val, u64 c_cost,
        const vector<u64> &values,
        const vector<u64> &costs,
        vector<pair<u64, u64>> &res) 
{
    if(c == values.size()) {
        if(c_val != 0 && (double)values.size() + log2(c_val) < 37.5)
            D("found: %lf\n",(double)values.size() + log2(c_val));
            res.emplace_back(c_cost, c_val);
        return;
    }

    if(c_cost + costs[c] <= capacity) {
        all_subsets(c+1, c_val + values[c], c_cost + costs[c], values, costs, res);
    }
    all_subsets(c+1, c_val, c_cost, values, costs, res);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    u64 tests;
    cin >> tests;
    while(tests--) {
        cin >> n >> capacity;
        D("tests: %llu %llu\n", n, capacity);

        u64 sum_val = 0;
        vector<u64> values1((n+1)/2);
        vector<u64> costs1((n+1)/2);
        vector<u64> values2(n/2);
        vector<u64> costs2(n/2);
        for(u64 i = 0; i < n; i++) {
            if(i < (n+1)/2) {
                cin >> values1[i];
                sum_val += values1[i];
            } else {
                cin >> values2[i-((n+1)/2)];
                sum_val += values2[i-((n+1)/2)];
            }
        }
        for(u64 i = 0; i < n; i++) {
            if(i < n/2)
                cin >> costs1[i];
            else
                cin >> costs2[i-(n/2)];
        }
        vector<pair<u64, u64>> res1;
        vector<pair<u64, u64>> res2;
        res1.reserve(10000000);
        res2.reserve(10000000);
        D("ss 1\n");
        all_subsets(0, 0, 0, values1, costs1, res1);
        D("ss 2\n");
        all_subsets(0, 0, 0, values2, costs2, res2);
        D("sort\n");
        sort(res2.begin(), res2.end());
        vector<pair<u64, u64>> new_res2;
        new_res2.reserve(1000000);

        D("filter\n");
        u64 val_found = 0;
        for(u64 i = 1; i < res2.size(); i++) {
            if(res2[i].first != res2[i-1].first && res2[i-1].second > val_found) {
                new_res2.push_back(res2[i-1]);
                val_found = res2[i-1].second;
            }
        }
        if(new_res2[new_res2.size()-1].first != res2[res2.size()-1].first &&
                res2[res2.size()-1].second > val_found) {
                new_res2.push_back(res2[res2.size()-1]);
        }

        D("find res\n");
        u64 max_val = 0;
        for (auto &ss1 : res1) {
            auto e = lower_bound(new_res2.begin(), new_res2.end(),
                    make_pair(capacity - ss1.first, 20000000000ULL));
            if (capacity - ss1.first == 0) {
                max_val = max(max_val, ss1.second);
            } else {
                max_val = max(max_val, ss1.second + (e-1)->second);
            }
        }
        cout << max_val << "\n";

    }

    return 0;
}
