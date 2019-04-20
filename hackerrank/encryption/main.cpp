#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

//#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool is_char(char c) {
    return ('a' <= c && c <= 'z') || c == ' ';
}

int main() {
    string str;
    char c = (char)getchar_unlocked();
    while (is_char(c)) {
        str.push_back(c);
        c = (char)getchar_unlocked();
    }
    
    int rows = (int)floor(sqrt(str.size()));
    int cols = (int)ceil(sqrt(str.size()));
    if(rows*cols < (int)str.size()) 
        rows++;
    vector<vector<char>> matrix(rows, vector<char>(cols, ' '));
    for (int i = 0; i < (int)str.size(); i++) {
        matrix[i/cols][i%cols] = str[i];
    }
    
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (matrix[j][i] == ' ') break;
            printf("%c", matrix[j][i]);
        }
        printf(" ");
    }
    printf("\n");

    return 0;
}
