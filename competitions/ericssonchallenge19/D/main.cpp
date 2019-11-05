#include <bits/stdc++.h>
using namespace std;

const unsigned long long p1 = 18014398241046527ULL;
const unsigned long long p2 = 1125899839733759ULL;
vector<string> words;
vector<unsigned long long> words1;
vector<unsigned long long> words2;
// begin, idx in words
vector<pair<int, int>> g;
bool amb = false;
bool found = false;
vector<string> res;

unsigned long long hash1(string s) {
    unsigned long long res1 = 0;
    unsigned long long res2 = 0;
    unsigned long long l = s.length()-1;
    res1 += s[0]*s[0] % p1;
    for (size_t i = 1; i < s.length()-1;i++) {
        res2 += s[i]*s[i] % p1;
    }
    res1 = res1 * res2 % p1;
    res1 = res1 * s[l]*s[l]*s[l] % p1;
    return res1;
}
unsigned long long hash2(string s) {
    unsigned long long res1 = 0;
    unsigned long long res2 = 0;
    unsigned long long l = s.length()-1;
    res1 += s[0]*s[0]*s[0] % p2;
    for (size_t i = 1; i < s.length()-1;i++) {
        res2 += s[i]*s[i]*s[i] % p2;
    }
    res1 = res1 * res2 % p2;
    res1 = res1 * s[l]*s[l]*s[l]*s[l] % p2;
    return res1;
}


int dfs(string s, int i, vector<string> v) {
    int ret = 0;
    if (i == (int)s.length()) {
        if (found) {
            cout << "ambiguous\n";
            exit(0);
        }
        res = v;
        found = true;
        return 1;
    }
    for (int j = 1; j <= (int)s.length()-i; j++) {
        unsigned long long h1 = hash1(s.substr(i,j));
        unsigned long long h2 = hash2(s.substr(i,j));
        for (int k = 0; k < (int)words.size(); k++) {
            if (h1 == words1[k] && h2 == words2[k]) {
                v.push_back(words[k]);
                ret = max(ret, dfs(s, i+(int)words[k].length(), v));
                v.pop_back();
            }
        }
    }
    return ret;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    while(n--) {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);
        words1.push_back(hash1(tmp));
        words2.push_back(hash2(tmp));
    }
    vector<string> v;
    if(dfs(s, 0, v)) {
        for(auto s : res) {
            cout << s << " ";
        }
        cout << endl;
    } else {
        cout << "impossible\n";
    }
    return 0;
}
