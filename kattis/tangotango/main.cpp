/**
 *  Welcome to 'if'-city!
 */
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9
#define MAX (int)1e10

#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;

enum Foot {
    up = 4,
    right = 1,
    down = 2,
    left = 3
};

int mem[1001][5][5][3];
const int max_go_to = 1001*1001 + 5*100 + 5*10 + 4;
pii go_to[1001*1001 + 5*100 + 5*10 + 4];
string arrows;

/**
 *  last = 1:
 *      any move: 1
 *  else :
 *      no move: 3
 *      adjacent: 5
 *      across: 7
 */
int solve(
        int current, 
        Foot left, 
        Foot right, 
        int last) 
{
    if(current >= (int)arrows.size()) {
        return 0;
    }
    if(mem[current][left][right][last] != -1) {
        return mem[current][left][right][last];
    }

    int res = MAX;
    int tmp = MAX;
    if(arrows[current] == '.') {
        tmp = min(res, solve(current + 1, left, right, 0));
        if(tmp < res) {
            res = tmp;
            go_to[current*1001+left*100+right*10+last] = 
                {(current+1)*1001+left*100+right*10+0, 0};
        }
        // Add all movements
        // Left
        if (left == Foot::left) {
            if (right != Foot::up) {
                tmp = min(res, solve(current + 1, Foot::up, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::up*100+right*10+1, 1};
                }
            }
            if (right != Foot::down) {
                tmp = min(res, solve( current + 1, Foot::down, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::down*100+right*10+1, 1};
                }
            }
            if (right != Foot::right) {
                tmp = min(res, solve( current + 1, Foot::right, right, 1) + (last == 1 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::right*100+right*10+1, 1};
                }
            }
        }
        if (left == Foot::right && right != Foot::left) {
            if (right != Foot::up) {
                tmp = min(res, solve( current + 1, Foot::up, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::up*100+right*10+1, 1};
                }
            }
            if (right != Foot::down) {
                tmp = min(res, solve( current + 1, Foot::down, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::down*100+right*10+1, 1};
                }
            }
            if (right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::left, right, 1) + (last == 1 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::left*100+right*10+1, 1};
                }
            }
        }
        if (left == Foot::up && right != Foot::left) {
            if (right != Foot::right) {
                tmp = min(res, solve( current + 1, Foot::right, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::right*100+right*10+1, 1};
                }
            }
            if (right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::left, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::left*100+right*10+1, 1};
                }
            }
            if (right != Foot::down) {
                tmp = min(res, solve( current + 1, Foot::down, right, 1) + (last == 1 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::down*100+right*10+1, 1};
                }
            }
        }
        if (left == Foot::down && right != Foot::left) {
            if (right != Foot::right) {
                tmp = min(res, solve( current + 1, Foot::right, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::right*100+right*10+1, 1};
                }
            }
            if (right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::left, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::left*100+right*10+1, 1};
                }
            }
            if (right != Foot::up) {
                tmp = min(res, solve( current + 1, Foot::up, right, 1) + (last == 1 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::up*100+right*10+1, 1};
                }
            }
        }
        // Right
        if (right == Foot::right) {
            if (left != Foot::up) {
                tmp = min(res, solve( current + 1, left, Foot::up, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::up*10+2, 2};
                }
            }
            if (left != Foot::down) {
                tmp = min(res, solve( current + 1, left, Foot::down, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::down*10+2, 2};
                }
            }
            if (left != Foot::left) {
                tmp = min(res, solve( current + 1, left, Foot::left, 2) + (last == 2 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::left*10+2, 2};
                }
            }
        }
        if (right == Foot::left && left != Foot::right) {
            if (left != Foot::up) {
                tmp = min(res, solve( current + 1, left, Foot::up, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::up*10+2, 2};
                }
            }
            if (left != Foot::down) {
                tmp = min(res, solve( current + 1, left, Foot::down, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::down*10+2, 2};
                }
            }
            if (left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::right, 2) + (last == 2 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::right*10+2, 2};
                }
            }
        }
        if (right == Foot::up && left != Foot::right) {
            if (left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::right, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::right*10+2, 2};
                }
            }
            if (left != Foot::left) {
                tmp = min(res, solve( current + 1, left, Foot::left, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::left*10+2, 2};
                }
            }
            if (left != Foot::down) {
                tmp = min(res, solve( current + 1, left, Foot::down, 2) + (last == 2 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::down*10+2, 2};
                }
            }
        }
        if (right == Foot::down && left != Foot::right) {
            if (left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::right, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::right*10+2, 2};
                }
            }
            if (left != Foot::left) {
                tmp = min(res, solve( current + 1, left, Foot::left, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::left*10+2, 2};
                }
            }
            if (left != Foot::up) {
                tmp = min(res, solve( current + 1, left, Foot::up, 2) + (last == 2 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::up*10+2, 2};
                }
            }
        }
    } else if(arrows[current] == 'U') {
        if (left == Foot::up) {
            tmp = min(res, solve( current + 1, left, right, 1) + (last == 1 ? 3 : 1));
            if(tmp < res) {
                res = tmp;
                go_to[current*1001+left*100+right*10+last] = 
                {(current+1)*1001+left*100+right*10+1, 1};
            }
        } else if(right == Foot::up) {
            tmp = min(res, solve( current + 1, left, right, 2) + (last == 2 ? 3 : 1));
            if(tmp < res) {
                res = tmp;
                go_to[current*1001+left*100+right*10+last] = 
                {(current+1)*1001+left*100+right*10+2, 2};
            }
        } else {
            // Move left to up (adjacent)
            if (left == Foot::left) {
                tmp = min(res, solve( current + 1, Foot::up, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::up*100+right*10+1, 1};
                }
            }
            if (left == Foot::right && right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::up, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::up*100+right*10+1, 1};
                }
            }

            // Move right to up (adjacent)
            if (right == Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::up, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::up*10+2, 2};
                }
            }
            if (right == Foot::left && left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::up, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::up*10+2, 2};
                }
            }

            // Move left to up (across)
            if(left == Foot::down && right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::up, right, 1) + (last == 1 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::up*100+right*10+1, 1};
                }
            }

            // Move right to up (across)
            if(right == Foot::down && left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::up, 2) + (last == 2 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::up*10+2, 2};
                }
            }
        }
    } else if(arrows[current] == 'R') {
        if (left == Foot::right) {
            tmp = min(res, solve( current + 1, left, right, 1) + (last == 1 ? 3 : 1));
            if(tmp < res) {
                res = tmp;
                go_to[current*1001+left*100+right*10+last] = 
                {(current+1)*1001+left*100+right*10+1, 1};
            }
        } else if (right == Foot::right) {
            tmp = min(res, solve( current + 1, left, right, 2) + (last == 2 ? 3 : 1));
            if(tmp < res) {
                res = tmp;
                go_to[current*1001+left*100+right*10+last] = 
                {(current+1)*1001+left*100+right*10+2, 2};
            }

        } else {
            // Move left to right (adjacent)
            if (left == Foot::up && right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::right, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::right*100+right*10+1, 1};
                }
            }
            if (left == Foot::down && right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::right, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::right*100+right*10+1, 1};
                }
            }

            // Move right to right (adjacent)
            if (right == Foot::down && left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::right, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::right*10+2, 2};
                }
            }
            if (right == Foot::up && left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::right, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::right*10+2, 2};
                }
            }

            // Move left to right (across)
            if(left == Foot::left) {
                tmp = min(res, solve( current + 1, Foot::right, right, 1) + (last == 1 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::right*100+right*10+1, 1};
                }
            }

            // Move right to right (across)
            if(right == Foot::left && left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::right, 2) + (last == 2 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::right*10+2, 2};
                }
            }
        }
    } else if(arrows[current] == 'D') {
        if (left == Foot::down) {
            tmp = min(res, solve( current + 1, left, right, 1) + (last == 1 ? 3 : 1));
            if(tmp < res) {
                res = tmp;
                go_to[current*1001+left*100+right*10+last] = 
                {(current+1)*1001+left*100+right*10+1, 1};
            }
        } else if(right == Foot::down) {
            tmp = min(res, solve( current + 1, left, right, 2) + (last == 2 ? 3 : 1));
            if(tmp < res) {
                res = tmp;
                go_to[current*1001+left*100+right*10+last] = 
                {(current+1)*1001+left*100+right*10+2, 2};
            }
        } else {
            // Move left to right (adjacent)
            if (left == Foot::left) {
                tmp = min(res, solve( current + 1, Foot::down, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::down*100+right*10+1, 1};
                }
            }
            if (left == Foot::right && right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::down, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::down*100+right*10+1, 1};
                }
            }

            // Move right to right (adjacent)
            if (right == Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::down, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::down*10+2, 2};
                }
            }
            if (right == Foot::left && left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::down, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::down*10+2, 2};
                }
            }

            // Move left to right (across)
            if(left == Foot::up && right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::down, right, 1) + (last == 1 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::down*100+right*10+1, 1};
                }
            }

            // Move right to right (across)
            if(right == Foot::up && left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::down, 2) + (last == 2 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::down*10+2, 2};
                }
            }
        }
    } else if(arrows[current] == 'L') {
        if (left == Foot::left) {
            tmp = min(res, solve( current + 1, left, right, 1) + (last == 1 ? 3 : 1));
            if(tmp < res) {
                res = tmp;
                go_to[current*1001+left*100+right*10+last] = 
                {(current+1)*1001+left*100+right*10+1, 1};
            }
        } else if (right == Foot::left) {
            tmp = min(res, solve( current + 1, left, right, 2) + (last == 2 ? 3 : 1));
            if(tmp < res) {
                res = tmp;
                go_to[current*1001+left*100+right*10+last] = 
                {(current+1)*1001+left*100+right*10+2, 2};
            }

        }else {
            // Move left to right (adjacent)
            if (left == Foot::up && right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::left, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::left*100+right*10+1, 1};
                }
            }
            if (left == Foot::down && right != Foot::left) {
                tmp = min(res, solve( current + 1, Foot::left, right, 1) + (last == 1 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::left*100+right*10+1, 1};
                }
            }

            // Move right to right (adjacent)
            if (right == Foot::down && left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::left, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::left*10+2, 2};
                }
            }
            if (right == Foot::up && left != Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::left, 2) + (last == 2 ? 5 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::left*10+2, 2};
                }
            }

            // Move left to right (across)
            if(left == Foot::right) {
                tmp = min(res, solve( current + 1, Foot::left, right, 1) + (last == 1 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+Foot::left*100+right*10+1, 1};
                }
            }

            // Move right to right (across)
            if(right == Foot::right) {
                tmp = min(res, solve( current + 1, left, Foot::left, 2) + (last == 2 ? 7 : 1));
                if(tmp < res) {
                    res = tmp;
                    go_to[current*1001+left*100+right*10+last] = 
                    {(current+1)*1001+left*100+Foot::left*10+2, 2};
                }
            }
        }
    }

    mem[current][left][right][last] = res;
    return res;
}

int main() {
    arrows.reserve(1001);
    while(true) {
        arrows.clear();
        char c = getchar_unlocked();
        while(c != '\n') {
            arrows.push_back(c);
            c = getchar_unlocked();
        }
        if(arrows[0] == '#') break;
        for (int a = 0; a < 1001; a++) {
            for (int b = 0; b < 5; b++) {
                for (int c = 0; c < 5; c++) {
                    for (int d = 0; d < 3; d++) {
                        mem[a][b][c][d] = -1;
                        go_to[1001*a + 100*b + 10*c + d] = {-1, -1};
                    }
                }
            }
        }
        solve(0, Foot::left, Foot::right, 0);
        int tmp = 1001*0+100*Foot::left + 10*Foot::right + 0;
        while(tmp > 1 && tmp < max_go_to) {
            if (go_to[tmp].second == 1) {
                printf("L");
            }
            if (go_to[tmp].second == 2) {
                printf("R");
            }
            if (go_to[tmp].second == 0) {
                printf(".");
            }
            tmp = go_to[tmp].first;
        }
        printf("\n");
    }

    return 0;
}
