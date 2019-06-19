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

using namespace std;

int memo[5000][5000];

string s, s1, s2;

int testHomework(int i, int j)
{
    if(memo[i][j] != 0)
        return memo[i][j];

    if(i == (int)s1.size() && j == (int)s2.size())
    {
        memo[i][j] = 1;
        return 1;
    }

    if(i < (int)s1.size() && s[i+j] == s1[i] && j < (int)s2.size() && s[i+j] == s2[j])
    {
        int goi = testHomework(i+1, j);
        int goj = testHomework(i, j+1);
        memo[i][j] = max(goi, goj);
        return memo[i][j];
    }
    else if(i < (int)s1.size() && s[i+j] == s1[i])
    {
        memo[i][j] = testHomework(i+1, j);
        return memo[i][j];
    }
    else if(j < (int)s2.size() && s[i+j] == s2[j])
    {
        memo[i][j] = testHomework(i, j+1);
        return memo[i][j];
    }
    else
    {
        memo[i][j] = -1;
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> s1 >> s2;
    int res = testHomework(0, 0);
    
    cout << (res == 1 ? "yes\n" : "no\n");

    return 0;
}
