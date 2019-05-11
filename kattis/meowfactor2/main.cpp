#include <bits/stdc++.h>
#include "substring_search.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

const unsigned long long MOD_PRIME = 922337220451ULL;
const unsigned long long ONE_PRIME = 16069ULL;
const unsigned long long INV_PRIME = 184249329619ULL;

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;

popup::AhoCorasickAutomaton<std::pair<size_t, string>> automaton;

void add_pattern(string &s, size_t idx, size_t value, size_t dots) {
    if (dots == 0) {
        automaton.add_string(s, {value, s});
        return;
    }
    for (size_t i = idx; i < s.size(); i++) {
        if (s[i] == '.') {
            for (char c = 'a'; c <= 'z'; c++) {
                s[i] = c;
                add_pattern(s, idx+1, value, dots-1);
                s[i] = '.';
            }
        }
    }
}

void add_patterns(vector<pair<string, int>> patterns) {
    for (auto p : patterns) {
        size_t dots = 0;
        for (size_t i = 0; i < p.first.size(); i++) {
            if (p.first[i] == '.') {
                dots++;
            }
        }
        if (!dots) {
            automaton.add_string(p.first, {p.second, p.first});
        } else {
            add_pattern(p.first, 0, p.second, dots);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<pair<string, int>> patterns;

    patterns.emplace_back("m", 3);
    patterns.emplace_back("e", 3);
    patterns.emplace_back("o", 3);
    patterns.emplace_back("w", 3);

    patterns.emplace_back("m..w", 2);
    patterns.emplace_back("m.w", 2);
    patterns.emplace_back("e.w", 2);
    patterns.emplace_back("m.o", 2);
    
    patterns.emplace_back("me", 2);
    patterns.emplace_back("mo", 2);
    patterns.emplace_back("mw", 2);
    patterns.emplace_back("eo", 2);
    patterns.emplace_back("ew", 2);
    patterns.emplace_back("ow", 2);

    //insert
    patterns.emplace_back("mew", 1);
    patterns.emplace_back("mow", 1);
    patterns.emplace_back("eow", 1);
    patterns.emplace_back("meo", 1);

    // swap
    patterns.emplace_back("moew", 1);

    // delete
    patterns.emplace_back("me.ow", 1);

    // replace
    patterns.emplace_back("me.w", 1);
    patterns.emplace_back("m.ow", 1);

    patterns.emplace_back("meow", 0);

    add_patterns(patterns);
    automaton.build_automaton();
    string text;
    cin >> text;

    size_t changes_needed = 4;
    for (auto itr = text.begin(); itr != text.end(); itr++) {
        auto opt_res = automaton.feed_char(*itr);
        if (opt_res.has_value()) {
            for (auto [pattern_value, nothing_really] : opt_res.value()) {
                changes_needed = min(changes_needed, pattern_value);
            }
        }
    }

    cout << changes_needed << endl;
    return 0;
}
