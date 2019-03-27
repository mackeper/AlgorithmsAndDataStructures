#include <algorithm>
#include <unordered_map>
#include <stdio.h>

using namespace std;

int main() {
    int bound;
    scanf("%d", &bound);
    
    unordered_map<int, int> map;

    int best = 0;
    for(int i = 0; i < 75; i++) {
        for(int j = i; j < 75; j++) {
            if (i==j) continue;
            int res = i*i*i+j*j*j;
            if(res > bound) break;
            if(map.find(res) == map.end())
                map[res] = 1;
            else 
                map[res]++;
        }
    }

    for(auto p : map) {
        if(p.second >= 2)
            best = max(best, p.first);
    }

    if(best)
        printf("%d\n",best);
    else
        printf("none\n");

    return 0;
}
