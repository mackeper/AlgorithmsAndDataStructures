#ifndef ROLLING_HASH_ 
#define ROLLING_HASH_

#include <iostream>

unsigned long long rolling_hash(std::string const& s)
{
    unsigned long long hash_value = 0;
    unsigned long long p_pow = 1;
    const unsigned long long m = 922337220451ULL;
    const unsigned long long p = 16069ULL;
    for (char c : s) {
        unsigned long long val = c;
        hash_value = (hash_value + (val) * p_pow) % m;
        p_pow = p_pow *p % m ;
    }

    return hash_value;
}

#endif // ROLLING_HASH_
