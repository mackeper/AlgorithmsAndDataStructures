#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "input.hpp"
using namespace std;

typedef int i64;
pair<i64, i64> prev_next[200000];
__gnu_pbds::gp_hash_table<i64, i64> prevm;
bool global_done = true;

inline bool alone(i64 i, i64 b, i64 e) {
    return prev_next[i].first < b && e <= prev_next[i].second;
}

inline void solve(i64 b, i64 e) {
    if (e - b < 2 || !global_done) {
        return;
    }

    i64 piv1 = b;
    i64 piv2 = e-1;

    while(piv1 <= piv2) {
        if (alone(piv2, b, e)) {
            solve(b, piv2); solve(piv2+1, e);  
            return;
        }
        if (alone(piv1, b, e)) {
            solve(b, piv1); solve(piv1+1, e);  
            return;
        }
        piv1++;
        piv2--;
    }

    global_done = false;
}

int main() {
    i64 tests;
    input::scanint(&tests);
    while(tests--) {
        i64 n;
        input::scanint(&n);
        prevm.clear();
        global_done = true;
        for(i64 i = 0; i < n; i++) {
            i64 t;
            input::scanint(&t);
            if (prevm.find(t) != prevm.end()) {
                prev_next[i].first = prevm[t];
                prev_next[i].second = 200010;
                prev_next[prevm[t]].second = i;
            } else {
                prev_next[i].first = -10;
                prev_next[i].second = 200010;
            }
            prevm[t] = i;
        }

        solve(0, n);
        puts((global_done ? "non-boring" : "boring"));
    }

    return 0;
}

