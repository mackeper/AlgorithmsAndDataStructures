#include "input.hpp"
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    input::scanint(&n);
    map<int, int> tree;

    int64_t C = 0;
    int key;
    for(int i = 0; i < n; i++) {
        input::scanint(&key);
        int depth = 0;
        auto it = tree.lower_bound(key);
        // Look at one larger
        if(it != tree.end()) {
            depth = it->second;
        } 
        // Look at one smaller
        if(it != tree.begin()) {
            auto smaller_it = it;
            smaller_it--;

            // Add the new key to the smaller or larger key which got the largest depth.
            if(depth < smaller_it->second) {
                depth = smaller_it->second;
                it = smaller_it;
            }

        }
    
        // The root should have depth 0
        if(i != 0)
            depth += 1;

        tree.insert(it, make_pair(key, depth));
        C += depth;
        printf("%li\n", C);

    }
    return 0;
}
