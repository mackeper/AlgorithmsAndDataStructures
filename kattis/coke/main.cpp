#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9
#define MAX (int)1e9

const unsigned long long MOD_PRIME = 922337220451ULL;
const unsigned long long ONE_PRIME = 16069ULL;
const unsigned long long INV_PRIME = 184249329619ULL;

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
int mem[151][100][101];

int buy_cokes(
        int cokes, 
        int in_machine, 
        int ones, int fives)
{
    if (mem[cokes][in_machine][fives] != 0) {
        return mem[cokes][in_machine][fives];
    }

    if(in_machine >= 8) {
        cokes--;
        ones += in_machine - 8;
        in_machine = 0;
    }

    if(cokes == 0) {
        return 0;
    }

    int res = MAX;
    if (ones > 0)
            res = min(res, 1 + buy_cokes(cokes, in_machine+1, ones-1, fives));
    if (fives > 0)
            res = min(res, 1 + buy_cokes(cokes, in_machine+5, ones, fives-1));

    mem[cokes][in_machine][fives] = res;
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int tests;
    cin >> tests;
    while(tests--) {
        int cokes;
        int coins[3];
        int values[3] = {1, 5, 10};
        memset(mem, 0, sizeof(mem));
        cin >> cokes >> coins[0] >> coins[1] >> coins[2];

        int total = 0;
        while (cokes > 0 && coins[2] > 0) {
            total++;
            coins[2]--;
            coins[0] += 2;
            cokes--;
        }

        int res = buy_cokes(cokes, 0, coins[0], coins[1]);
        if (res != MAX)
            cout << res + total << endl;
        else
            cout << total << endl;
    }

    return 0;
}
