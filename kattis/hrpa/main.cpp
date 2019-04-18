#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

vector<size_t> fib_nr;
size_t fib(size_t cnt) {
    size_t j = 1;
    size_t res = 0;
    for(size_t i = 0; res <= cnt; i++) {
        if(res == cnt) {
            cout << res << endl;
            exit(0);
        }
        fib_nr.push_back(res);
        size_t tmp = res;
        res += j;
        j = tmp;
    }

    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    size_t n;
    cin >> n;

    fib(n);
    while(1) {
        size_t t = *(upper_bound(fib_nr.begin(), fib_nr.end(), n)-1);
        if(t >= n) break;
        n -= t;
    }
    cout << (size_t)(n) << endl;

    return 0;
}
