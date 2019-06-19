#include <bits/stdc++.h>
#include "polygons.hpp"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9
#define i64MAX = (i64)1e15;

const unsigned long long MOD_PRIME = 922337220451ULL;
const unsigned long long ONE_PRIME = 16069ULL;
const unsigned long long INV_PRIME = 184249329619ULL;

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

template <typename T>
int sign(T n) {
    return (int)(T(0) < n) - (int)(n < T(0));
}


class LineSeg {
public:
    double x1, y1, x2, y2;
    
    LineSeg() {
        x1 = 0; y1 = 0; x2 = 0; y2 = 0;
    }
    LineSeg(double x1, double y1, double x2, double y2) {
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};

bool line_intersect(LineSeg &l1, LineSeg &l2) {
    return popup::line_intersect<double>(
        {{l1.x1, l1.y1}}, {{l1.x2, l1.y2}},
        {{l2.x1, l2.y1}}, {{l2.x2, l2.y2}}
    );
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int m;
    while (cin >> m && m != 0) {
        vector<LineSeg> lines(m);
        for (auto &l : lines) {
            cin >> l.x1 >> l.y1 >> l.x2 >> l.y2;
        }
        
        size_t res = 0;
        for (size_t a = 0; a < lines.size(); a++) {
            for (size_t b = a+1; b < lines.size(); b++) {
                for (size_t c = b+1; c < lines.size(); c++) {
                    if (a != b 
                        && a != c 
                        && line_intersect(lines[a], lines[b])
                        && line_intersect(lines[b], lines[c])
                        && line_intersect(lines[c], lines[a])
                        ) {
                        res++;
                    }
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}
