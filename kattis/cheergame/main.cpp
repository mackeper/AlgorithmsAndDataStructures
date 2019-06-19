#include <iostream>     // cout, cin
#include <list>         // list: push_front, push_back... pop...
#include <algorithm>    // sort, min, max
#include <limits>       // std::numeric_limits<T>::infinity()
#include <vector>       // vector
#include <utility>      // pair, make_pair(1,2)
#include <string>
#include <sstream>      // stringstream ss(string str)
#include <unordered_map> // hash map
#include <map>          // red-black tree
#include <cstdio>       // printf
#include <cstring>       // memset

using namespace std;


struct goals
{
    int A;
    int B;
};


int cheerleaders;
int spoilsEachMin[90];
goals arr[20*90+1][91][5][3];
bool arrset[20*90+1][91][5][3];
pair<int, int> intervals[1001];

// maxdiff: maximizes A-B, if equal maximize A
goals& maxdiff(goals &g1, goals &g2)
{
    if((g1.A - g1.B) > (g2.A - g2.B)) {
        return g1;
    } else if((g1.A - g1.B) == (g2.A - g2.B)){
        if(g1.A > g2.A){
            return g1;
        } else {
            return g2;
        }
    } else {
        return g2;
    }
}

goals testCheer(int m, int cheersleft, int score, int win) {
    if(arrset[cheersleft][m][score][win])
        return arr[cheersleft][m][score][win];

    if(m == 45)
        score = 0;

       
    if(m == 90) {
        goals g = {0, 0};
        arr[cheersleft][m][score][win] = g;
        arrset[cheersleft][m][score][win] = true;
        return g;
    }

    goals g1 = {0, numeric_limits<int>::max()};
    goals g2 = {0, numeric_limits<int>::max()};
    goals g3 = {0, numeric_limits<int>::max()};

    // Sportify wins this minute
    if(cheerleaders > spoilsEachMin[m] && cheersleft > spoilsEachMin[m])
    {
        int tScore = win == 1 ? score+1 : 1;
        g1 = testCheer(m + 1, cheersleft - spoilsEachMin[m] - 1, tScore%5, 1);
        if(tScore == 5)
            g1.A++;
    }

    // Minute is equal
    if(cheerleaders >= spoilsEachMin[m] && cheersleft >= spoilsEachMin[m])
        g2 = testCheer(m+1, cheersleft - spoilsEachMin[m], 0, 0);

    
    // Spoilify wins this minute
    if(spoilsEachMin[m] > 0)
    {
        int tScore = win == 2 ? score+1 : 1;
        g3 = testCheer(m+1, cheersleft, tScore%5, 2);
        if(tScore == 5)
            g3.B++;
    } 
    
    // maxdiff: maximizes A-B, if equal maximize A
    goals ans = maxdiff(g1, maxdiff(g2, g3));
    arr[cheersleft][m][score][win] = ans;
    arrset[cheersleft][m][score][win] = true;
    return ans;
}

void scanint(int *x) {
    int c;
    *x = getchar_unlocked() - 48;
    while (48 <= (c = getchar_unlocked())) *x = (*x<<3) + (*x<<1) + c - 48;
}

int main()
{
    int energy, spoilifyIntervals;
    scanint(&cheerleaders);
    scanint(&energy);
    scanint(&spoilifyIntervals);
    
    for(int i = 0; i < spoilifyIntervals; i++) {
        int a, b;
        scanint(&a);
        scanint(&b);
        intervals[i] = make_pair(a,b);
        for(int i = a; i < b; i++)
            spoilsEachMin[i]++;
    }

    goals g1 = testCheer(0, cheerleaders*energy, 0, 0);

    cout << g1.A << " " << g1.B << endl;

    return 0;
}
