#include <bits/stdc++.h>
#include "numeric.hpp"
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long i64;
typedef unsigned long long u64;

void find_factors(
        vector<u64> &divisors,
        vector<u64> &amount,
        vector<u64> &result,
        u64 currentDivisor,
        u64 currentResult) {
    if (currentDivisor == divisors.size()) {
        result.push_back(currentResult);
        return;
    }

    for (u64 i = 0; i <= amount[currentDivisor]; i++) {
        find_factors(divisors, amount, result, currentDivisor + 1, currentResult);
        currentResult *= divisors[currentDivisor];
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    SieveCache sc(1e7);

    int tests;
    cin >> tests;
    while(tests--) {
        u64 n;
        cin >> n;
        u64 sum = 0;
        vector<u64> a;
        vector<u64> b;
        vector<u64> c;
        u64 start_n = n;
        for(u64 i = 0; i < sc.primes_found() && sc[i]*sc[i] <= start_n; i++) {
            if(n % sc[i] == 0) {
                n /= sc[i];
                a.push_back(sc[i]);  
                b.push_back(1);
                while(n % sc[i] == 0) {
                    b[b.size()-1]++;
                    n /= sc[i];
                }
                D("Div: %lld %lld\n", a[a.size()-1], b[b.size()-1]);
            }
        }

        if (a.size() == 0 || n != 1) {
            a.push_back(n);
            b.push_back(1);
        }
        find_factors(a, b, c, 0, 1);

        for(auto &i : c) {
            D("divisor: %llu phi: %lu sum: %llu\n", i, sc.phi(i+1), sum);
            sum += sc.phi(i+1);
        }
        cout << sum << endl;
    }

    return 0;
}
