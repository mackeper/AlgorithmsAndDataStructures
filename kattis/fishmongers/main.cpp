#include <bits/stdc++.h>
#include "input.hpp"
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
    int num_fish, num_mongers;
    input::scanint(&num_fish);
    input::scanint(&num_mongers);
    vector<u64> weights(num_fish);
    for(auto &w : weights) {
        input::scanlong(&w);
    }

    vector<pair<u64 ,u64>> mongers(num_mongers);
    for(auto &m : mongers) {
        input::scanlong(&m.second);
        input::scanlong(&m.first);
    }

    sort(weights.begin(), weights.end());
    sort(mongers.begin(), mongers.end(), greater<pair<u64, u64>>());
    u64 sum = 0;
    for(auto &m : mongers) {
        if(weights.empty()) break;
        while(!weights.empty() && m.second > 0) {
            sum += weights.back()*m.first;
            weights.pop_back();
            m.second--;
        }
    }


    printf("%llu\n", sum);
    return 0;
}
