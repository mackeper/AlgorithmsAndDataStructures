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

int bin_search(int x, vector<int> &primes) {
    int l = 0, h = primes.size()-1;
    cerr << "------" << endl;
    while(l + 1 < h) {
        int mid = (l+h)/2;
        D("l: %d h: %d mid: %d x: %d res: %lf\n", l, h, mid, x,
                ((double)x/(double)primes[mid]));
        if(((double)x/(double)primes[mid]) >= 5) {
            l = mid;
        } else {
            h = mid;
        }
    }

    return l;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    const int N = 100;
    bool is_prime[N+1];
    fill(is_prime, is_prime + N + 1, true);
    int primes_before[N+1];
    fill(is_prime, is_prime + N + 1, 1);
    vector<int> primes;
    primes.push_back(1);
    int primes_found = 0;
    for (int i=2; i<=N; i++) {
        primes_before[i] = primes_found;
        if (is_prime[i] && (i - 1) % 4 == 0) {
            primes.push_back(i);
            primes_found++;
        }
        for (int j=0; j<N; j+=i)
            is_prime[i] = false;
    }

    int h;
    while(cin >> h && h != 0) {
        int h_div_idx = bin_search(h, primes);
        printf("%d %d\n", h_div_idx, primes[h_div_idx]);
    }

    return 0;
}
