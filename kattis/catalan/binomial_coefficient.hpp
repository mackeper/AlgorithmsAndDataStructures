#ifndef BINOMIAL_COEFFICIENT_
#define BINOMIAL_COEFFICIENT_
/**
 *  Binomial Coefficient
 *  Author: Marcus Östling
 *
 *  Inspired by: 
 *  https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
 */
#include <vector>
#include <algorithm>

namespace malg {
    /**
     * Calculates a lot but returns one value.
     */
    template <typename T>
    T binomial_coefficient(size_t n, size_t k)
    {
        std::vector<std::vector<T>> cache(n+1, std::vector<T>(k+1, T(0)));
        for (size_t i = 0; i <= n; i++) { 
            for (size_t j = 0; j <= std::min(i, k); j++) { 
                if (j == 0 || j == i) 
                    cache[i][j] = 1; 
                else
                    cache[i][j] = cache[i-1][j-1] + cache[i-1][j]; 
            } 
        } 

        return cache[n][k];
    }

    /**
     * Class that stores every binomial coefficient
     * from (n choose 0) to (n choose n)
     */
    template <typename T>
    class BinomialCoefficient {
        std::vector<std::vector<T>> cache_;
        T n_;
    public:
        BinomialCoefficient(size_t n) {
            this->n_ = n;

            cache_.resize(n+1, std::vector<T>(n+1, T(0)));
            for (size_t i = 0; i <= n; i++) { 
                for (size_t j = 0; j <= std::min(i, n); j++) { 
                    if (j == 0 || j == i) 
                        cache_[i][j] = T(1); 
                    else
                        cache_[i][j] = cache_[i-1][j-1] + cache_[i-1][j]; 
                } 
            } 
        }

        T get(size_t n, size_t k) {
            return this->cache_[n][k];
        }
    };
};

#endif // BINOMIAL_COEFFICIENT_
