#include <bits/stdc++.h>
#include "substring_search.hpp" 
using namespace std;

#define MAX (size_t)10e18

typedef long long ll;

unordered_map<char, char> key_map;
unordered_map<string, size_t> key_cnt; // string hash -> total number of that string
unordered_map<size_t, size_t> key_ord;
unordered_map<size_t, pair<size_t, string>> word_seq; // number of presses/string
unordered_map<size_t, string> str_map;
vector<string> patterns;
vector<size_t> patterns_h;

void str_to_keys(size_t pattern_idx) {
    stringstream ss;
    for(size_t i = 0; i < patterns[pattern_idx].size(); i++) {
        ss << key_map[patterns[pattern_idx][i]];
    }
    str_map[pattern_idx] = ss.str();
}

// true = positive
pair<bool, size_t> key_presses(size_t pattern_idx) {
    size_t cnt = key_cnt[str_map[pattern_idx]];
    size_t ord = key_ord[pattern_idx];
    size_t up = ord-1;
    size_t down = cnt-ord+1;
    if(ord == 0) {
        return {true, 0};
    } else if(up <= down) {
        return {true, up};
    } else {
        return {false, down};
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    key_map['a'] = '2';
    key_map['b'] = '2';
    key_map['c'] = '2';
    key_map['d'] = '3';
    key_map['e'] = '3';
    key_map['f'] = '3';
    key_map['g'] = '4';
    key_map['h'] = '4';
    key_map['i'] = '4';
    key_map['j'] = '5';
    key_map['k'] = '5';
    key_map['l'] = '5';
    key_map['m'] = '6';
    key_map['n'] = '6';
    key_map['o'] = '6';
    key_map['p'] = '7';
    key_map['q'] = '7';
    key_map['r'] = '7';
    key_map['s'] = '7';
    key_map['t'] = '8';
    key_map['u'] = '8';
    key_map['v'] = '8';
    key_map['w'] = '9';
    key_map['x'] = '9';
    key_map['y'] = '9';
    key_map['z'] = '9';

    size_t num_patterns, num_queries;
    cin >> num_patterns;
    patterns.resize(num_patterns);
    patterns_h.resize(num_patterns);
    for (size_t i = 0; i < num_patterns; i++) {
        cin >> patterns[i];
        patterns_h[i] = hash<string>{}(patterns[i]);
        str_to_keys(i);
        if(key_cnt.find(str_map[i]) == key_cnt.end()) { 
            key_cnt[str_map[i]] = 1;
        } else {
            key_cnt[str_map[i]]++;
        }
        key_ord[i] = key_cnt[str_map[i]];
    }

    // string for each seq
    for (size_t i = 0; i < patterns.size(); i++) {
        auto [positive, presses] = key_presses(i);
        stringstream ss;
        ss << str_map[i];
        if(positive && presses > 0) {
            ss << "U(" << presses << ")";
        } else if (!positive && presses > 0) {
            ss << "D(" << presses << ")";
        } 
        word_seq[i] = {str_map[i].size()+presses, ss.str()};
    }

    popup::AhoCorasickAutomaton<pair<size_t, size_t>> automaton;

    unordered_set<size_t> added;
    for (size_t i = 0; i < patterns.size(); i++) {
        if(added.find(patterns_h[i]) == added.end()) {
            automaton.add_string(
                patterns[i],
                {i, patterns[i].size()}
            );
        added.insert(patterns_h[i]);
        }
    }
    automaton.build_automaton();

    cin >> num_queries;
    for(size_t i = 0; i < num_queries; i++) {
        string text;
        cin >> text;
        text += 'a';

        vector<size_t> d(text.size()+1, MAX);
        vector<pair<size_t, size_t>> cf(text.size()+1, {MAX, MAX});
        d[0] = 0;
        
        // Feed automaton and calculate distance
        for (size_t i = 0; i < text.size(); i++) {
            auto opt_res = automaton.feed_char(text[i]);
            if (opt_res.has_value()) {
                for (auto [pattern_idx, match_size] : opt_res.value()) {
                    if(d[i-match_size+1] != MAX) {
                        size_t cost = d[i-match_size+1] + word_seq[pattern_idx].first;
                        if(i+1 != text.size()) cost++;
                        if (d[i+1] > cost) {
                            d[i+1] = cost;
                            cf[i+1] = {i-match_size+1, pattern_idx};
                        }
                    }
                }
            }
        }

        // reverse and backtrack
        stack<size_t> output;
        for(size_t i = text.size()-1; i != MAX && i > 0; i = cf[i].first) {
            output.push(cf[i].second);
        }
        
        // Output
        while(!output.empty()) {
            cout << word_seq[output.top()].second;
            output.pop();
            if(output.size() > 0) {
                cout << "R";
            }
        }
        cout << "\n";
    }

    return 0;
}

