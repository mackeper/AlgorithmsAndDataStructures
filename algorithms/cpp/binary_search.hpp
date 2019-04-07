#ifndef BINARY_SEARCH_
#define BINARY_SEARCH_
/**
 *  Binary search
 *  Author: Marcus Östling
 */

#include <functional>
#include <iostream>
namespace malg {
template <typename T>
T binary_search(T low, T high, T find, std::function<T(T)> func) {
    while(low + 1 < high) {
        int64_t mid = (low+high)/2;
        if(func(mid) <= find) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}
} // namespace malg

#endif // BINARY_SEARCH_
