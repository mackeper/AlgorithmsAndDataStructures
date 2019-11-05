#include <bits/stdc++.h>
using namespace std;
#define EPS 10e-9

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;

u64 sum = 0;

void calc_hashes(
        u64 current, 
        u64 n, u64 k, u64 m, u64 len, 
        vector<i64> &res) 
{
    if(len == (n+1)/2) {
        res[current]++;
        return;
    }
    for(u64 i = 1; i <= 26; i++) {
        u64 new_current = ((current * 33) ^ i) % m;
        calc_hashes(new_current, n, k, m, len + 1, res);
    }

}

void calc_hashes_rev(
        u64 current, 
        u64 n, u64 k, u64 m, u64 len, 
        vector<i64> &res) 
{
    if(len == (n+1)/2) {
        sum += res[current];
        return;
    }
    for (u64 i = 1; i <= 26; i++) {
        u64 x;
        for (x = 1; x <= 33; x++) {
            if (((current+x*m)^i)%33 == 0) {
                break;
            }
        }
        u64 new_current = (((current+x*m)^i) / 33) % m;
        calc_hashes_rev(new_current, n, k, m, len + 1, res);
    }

}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    u64 N, K, M;
    cin >> N >> K >> M;
    u64 m = (u64)pow(2, M);

    vector<i64> res(m, 0);
    calc_hashes(0, N, K, m, 0, res);
    u64 len = N % 2 == 0 ? 0 : 1;
    calc_hashes_rev(K, N, K, m, len, res);
    cout << sum << endl;

    return 0;
}
