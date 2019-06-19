#include <iostream>
#include <cstdio>
#include "input.hpp"
#include "fenwick_tree.hpp"
#include <utility>


int movies[100000];

int main() {
    int tests;
    input::scanint(&tests);


    for(int t = 0; t < tests; t++) {
        int m, r;
        input::scanint(&m);
        input::scanint(&r);
    
        popup::Fenwicktree fen(m+r);
        
        for(int i = 0; i < m+r; i++) {
            if(i >= r) {
                fen.update(i, 1);
                movies[i-r] = i;
            }
        }

        int movie;
        for(int i = r-1; i >= 0; i--) {
            input::scanint(&movie);
            movie -= 1;
            int64_t movies_on_top = fen.sum(movies[movie]);
            printf("%li ", movies_on_top);
            fen.update(i, 1);
            fen.update(movies[movie], -1);
            movies[movie] = i;
        }
        
        printf("\n");
        
    }

    return 0;
}
