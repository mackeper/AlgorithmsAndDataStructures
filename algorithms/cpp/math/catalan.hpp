#ifndef CATALAN_NUMBERS_
#define CATALAN_NUMBERS_
/**
 *  Calatan numbers
 *  Author: Marcus Östling
 */
#include <vector>
#include <iostream>

namespace malg {
    template <typename T>
    class CatalanNumbers {
        std::vector<T> catalan_;
        size_t size_;
    public:
        explicit CatalanNumbers(size_t size) {
            this->size_ = size+1;
            this->catalan_.resize(size+1);
            this->catalan_[0] = T(1);
            this->catalan_[1] = T(1);

            for (size_t i = 2; i <= size; i++) {
                this->catalan_[i] = T(0);
                for (size_t j = 0; j < i; j++) {
                    this->catalan_[i] += 
                        this->catalan_[j] * this->catalan_[i-j-1];
                }
            }
        }

        T operator[](size_t i) const {
            return this->catalan_[i];
        }
    };
}

#endif // CATALAN_NUMBERS_
