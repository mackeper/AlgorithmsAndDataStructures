#include <bits/stdc++.h>
#include "suffix_array.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void lcp_construction(vector<int> &lcp, const vector<size_t>& suffix, string &s) {
    int n = (int)s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[suffix[i]] = i;

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = (int)suffix[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k]) {
            k++;
        }
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        popup::SuffixArray sa(str);
        vector<size_t> sav = sa.as_vector();
        
        int n = (int)str.size();
        if(n == 1) {
            cout << "0\n";
            continue;
        }
        vector<int> lcp(n-1, 0);
        lcp_construction(lcp, sav, str);
        int lcp_sum = lcp[0];
        for(int i = 0; i < n-2; i++) {
            if(lcp[i] < lcp[i+1]) {
                lcp_sum += lcp[i+1] - lcp[i];
            }
        }
        cout << lcp_sum << "\n";
    }

    return 0;
}
