#include <iostream>
#include <cstdio>
#include "input.hpp"
#include "fenwick_tree.hpp"
#include <cmath>

using namespace std;

void minmax(int &min, int &max) {
    if(min > max) {
        int tmp = min;
        min = max;
        max = tmp;
    }
}

int main() {
    int n;
    input::scanint(&n);

    popup::Fenwicktree fen(n+1);
    
    int v = 0;
    int starting[n+1];
    for(int i = 0; i < n; i++) {
        input::scanint(&v);
        starting[v-1] = i;
    }
    int a = 0;
    for(int i = 0; i < n; i++) {
        int index = i%2==0 ? i-a : n-i+a;
        int delta = i%2==0 ? 1 : -1;


        // in fen sum: +1 for inclusive
        int64_t currentPosition = starting[index] + fen.sum(starting[index]+1);

        printf("%li\n", abs(currentPosition-index));
        int min = starting[index];
        int max = i%2==0 ? 0 : n;
        minmax(min, max);
        if(abs(currentPosition-index) != 0) {
            if(max < n)
                max += 1;
            fen.update(min, delta);
            fen.update(max, -delta);
            //printf("Set fen (%d, %d), (%d, %d)\n", min, delta, max, -delta);
        }
        a = i%2==0 ? a : a+1;
    }
}
