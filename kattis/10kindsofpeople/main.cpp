#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include "union_find.hpp"
#include "input.hpp"

using namespace std;

int map[1000][1000];

int main() {
    int row, cols;
    input::scanint(&row);
    input::scanint(&cols);
    popup::UnionFind uf(row*cols+cols);
    
    char s[cols];
    for(size_t r = 0; r < row; r++) {
        input::scanstr(s, cols);
        getchar_unlocked(); // next line
        for(size_t c = 0; c < cols; c++) {
            map[r][c] = (int)s[c]-48;
            if(c != 0 && map[r][c-1] == map[r][c])
                uf.make_union(r*cols+c, r*cols+c-1);
            if(r != 0 && map[r-1][c] == map[r][c])
                uf.make_union(r*cols+c, (r-1)*cols+c);
        }
    }

    int queries;
    input::scanint(&queries);
    int r1,c1,r2,c2;

    for(int i = 0; i < queries; i++) {
        input::scanint(&r1);
        input::scanint(&c1);
        input::scanint(&r2);
        input::scanint(&c2);
        r1 -= 1; c1 -= 1; r2 -= 1; c2 -= 1;
        if(map[r1][c1] == map[r2][c2] && (uf.find(r1*cols+c1)==uf.find(r2*cols+c2)))
          printf("%s\n",(map[r1][c1] == 1 ? "decimal" : "binary"));
        else
            printf("neither\n");
    }

}
