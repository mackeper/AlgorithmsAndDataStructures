#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long u64;

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
        unsigned long long &hash,
        unsigned long long m,
        unsigned long long p)
{
    unsigned long long hash_value = 0;
    unsigned long long p_pow = 1;
    for (char c : s) {
        u64 val = c;
        hash_value = (hash_value + (val) * p_pow) % m;
        p_pow = p_pow *p % m ;
    }
    hash = hash_value;
}

void compute_hashes(
        string const& s,
        vector<unsigned long long> &hashes,
        unsigned long long m,
        unsigned long long p)
{
    unsigned long long hash_value = 0;
    unsigned long long p_pow = 1;
    for (char c : s) {
        u64 val = c;
        hash_value = (hash_value + (val) * p_pow) % m;
        hashes.push_back(hash_value);
        p_pow = p_pow *p % m ;
    }
}

int main() {
    u64 hp, wp, hm, wm;
    cin >> hp >> wp >> hm >> wm;
    const unsigned long long m = 922337220451ULL;
    const unsigned long long p = 16069ULL;
    vector<unsigned long long> inv(wm);
    inv[0] = 1;
    inv[1] = 184249329619ULL;
    for(unsigned long long i = 2; i < wm; i++) {
        inv[i] = mul_mod(inv[i-1], inv[1], m);
    }

    u64 p_hash;
    string p_str;
    for (u64 i = 0; i < hp; i++) {
        string s;
        cin >> s;
        for (auto c : s) 
            p_str.push_back(c);
    }
    compute_hash(p_str, p_hash, m, p);

    vector<vector<u64>> m_hashes(hm, vector<u64>());
    vector<string> m_strs((hm-hp+1)*(wm-wp+1)+1);
    for (u64 y = 0; y < hm; y++) {
        string s;
        cin >> s;
        for (u64 x = 0; x < wm; x++) {
            char c = s[x];
            for (long long i = 0; (long long)x-i >= 0 && i < 4 && x < wm-wp; i++) {
                cout << y << " " << (y*(wm-wp+1) + (x-i)) << endl;
                if((long long)x-i < (long long)(wm-wp))
                    m_strs[y*(wm-wp+1) + (x-i)].push_back(c);
            }
        }
    }

    for (string s : m_strs) {
        cout << s << endl;
    }

    u64 res = 0;

    // for (u64 y = 0; y <= hm - hp; y++) {
    //     for (u64 x = 0; x <= wm - wp; x++) {
    //         bool match = true;
    //         for (u64 p = 0;  p < hp; p++) {
    //             u64 tmp_hash;
    //             u64 tmp_x = x;
    //             u64 tmp_j = x + wp;
    //             tmp_j--;
    //             if(x == 0) {
    //                 tmp_hash = m_hashes[y+p][tmp_j];
    //             } else {
    //                 tmp_x--;
    //                 tmp_hash = mul_mod((m_hashes[y+p][tmp_j]+m
    //                             - m_hashes[y+p][tmp_x])%m, inv[tmp_x+1], m);
    //             }
    //             if(tmp_hash != p_hashes[p]) {
    //                 match = false;
    //                 break;
    //             }
    //         }
    //         if (match) {
    //             res++;
    //         }
    //     }
    // }

    cout << res << endl;

    return 0;
}
