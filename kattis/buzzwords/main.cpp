#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;

char next_char() {
    char c = getchar_unlocked();
    while(c == 32 || c == 10) {
        c = getchar_unlocked();
    }
    return c;
}

uint64_t next_word64() {
    char c = getchar_unlocked();
    while ('0' > c || '9' < c) {
        c = getchar_unlocked();
    }
    int x = 0;
    while ('0' <= c && c <= '9') {
        x = 10 * x + c - 48;
        c = getchar_unlocked();
    }
    return x;
}

bool valid_char(char c) {
    return ('A' <= c && c <= 'Z') || c == ' ';
}

unsigned long long mod(unsigned long long x, unsigned long long m) {
    return ((x % m) + m) % m;
}

uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m)
{
    long double x;
    uint64_t c;
    int64_t r;
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    x = a;
    c = x * b / m;
    r = (int64_t)(a * b - c * m) % (int64_t)m;
    return r < 0 ? r + m : r;
}

void compute_hash(
        string const& s,
        vector<unsigned long long> &hashes,
        unsigned long long m,
        unsigned long long p)
{
    unsigned long long hash_value = 0;
    unsigned long long p_pow = 1;
    for (char c : s) {
        //u64 val = c - 'A' + 1;
        //if (c == ' ') val = c - 'Z' + 2;
        u64 val = c;
        hash_value = (hash_value + (val) * p_pow) % m;
        hashes.push_back(hash_value);
        p_pow = p_pow *p % m ;
    }
}

int main() {

    while(1) {
        string str;
        char c = getchar_unlocked();
        while (valid_char(c)) {
            if (c != ' ')
                str.push_back(c);
            c = getchar_unlocked();
        }
        if(str.empty()) break;

        const unsigned long long m = 922337220451ULL;
        const unsigned long long p = 16069ULL;
        vector<unsigned long long> inv(str.size());
        inv[0] = 1;
        inv[1] = 184249329619ULL;
        for(unsigned long long i = 2; i < str.size(); i++) {
            inv[i] = mul_mod(inv[i-1], inv[1], m);
        }

        vector<unsigned long long> hashes;
        compute_hash(str, hashes, m, p);

        vector<u64> len_cnt(str.size()+1, 0);
        for(u64 sz = 1; sz < str.size(); sz++) {
            u64 curr_len_cnt = 0;
            unordered_map<u64, u64> hash_cnt;
            for(u64 i = 0; i <= str.size()-sz; i++) {
                u64 hash;
                u64 tmp = i;
                u64 j = tmp + sz;
                j--;
                if(i == 0) {
                    hash = hashes[j];
                } else {
                    tmp--;
                    hash = mul_mod((hashes[j]+m - hashes[tmp])%m, inv[tmp+1], m);
                }
                hash_cnt[hash]++;
                curr_len_cnt = max(curr_len_cnt, hash_cnt[hash]);
            }
            if(curr_len_cnt < 2) {
                cout << "\n";
                break;
            } else {
                cout << curr_len_cnt << "\n";
            }
        }
    }

    cout << "\n";

    return 0;
}
