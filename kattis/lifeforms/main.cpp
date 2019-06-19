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

void print_suffix(string &s, const vector<size_t>& suffix, int a) {
    for(int i = a, j = 0; j < (int)s.size() && s[i] != '$'; i++, j++) {
        cerr << s[i%((int)s.size())];
    }
    cerr << "\n";
}

vector<int> lcp_construction(const vector<size_t>& suffix, string &s) {
    int n = (int)s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[suffix[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = suffix[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k]) {
            k++;
        }
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int num_lifeforms;
    while(cin >> num_lifeforms && num_lifeforms > 0) {
        vector<int> str_idx(num_lifeforms);
        int current_idx = 0;
        stringstream ss;
        int min_size = 10000;
        for(int i = 0; i < num_lifeforms; i++) {
            string s;
            cin >> s;
            str_idx[i] = current_idx;
            current_idx += (int)s.size();
            min_size = min(min_size, (int)s.size());
            ss << s;
            ss << '~';
        }

        string total_str = ss.str();
        cerr << "total: " << total_str << endl;
        popup::CycleArray sa(total_str);
        vector<size_t> suff = sa.as_vector();
        vector<int> lcp = lcp_construction(sa.as_vector(), total_str);
        int lcp_len = lcp[0];
        int lcp_res = 0;
        vector<int> lcps;
        /*for(int i = 1; i < (int)total_str.size(); i++) {
            //cerr << "lcp[i]:" << lcp[i] << " < " << lcp_len << endl;
            //print_suffix(total_str, sa.as_vector(), i);
            if(lcp[i] < lcp_len) {
                lcp_len = lcp[i];
                lcp_res = i;
                lcps.clear();
                lcps.push_back(i);
            } else if (lcp[i] == lcp_len) {
                lcps.push_back(i);
            }
        }*/
        for(size_t i : suff) {
            print_suffix(total_str, suff, i);
        }
        cerr << "lcp: " << lcp_res << " len:" << lcp_len << " mul: " << lcps.size() << endl;
        for(int i : lcps) {
            print_suffix(total_str, sa.as_vector(), i);
        }
        cerr << endl;
    }

    return 0;
}
