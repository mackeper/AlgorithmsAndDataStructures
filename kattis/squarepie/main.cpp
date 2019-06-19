#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

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

void fastscan(i64 &number) { 
    bool negative = false; 
    i64 c; 
    number = 0; 
    c = getchar_unlocked(); 
    if (c=='-') { 
        negative = true; 
        c = getchar_unlocked(); 
    } 
    for (; (c>47 && c<58); c=getchar_unlocked()) 
        number = number *10 + c - 48; 
  
    if (negative) 
        number *= -1; 
} 

class Point {
    public:
        i64 x, y;
        Point() : x(0), y(0) {}
        Point(i64 x, i64 y) : x(x), y(y) {}
};

class LineSeg {
    public:
        Point start, end;
        i64 x_up, x_down;
        LineSeg(Point a, Point b) : start(a), end(b) {
            x_up =      a.x;
            x_down =    a.x;
        }
        LineSeg(const LineSeg& other) : start(other.start), end(other.end) {
            x_up    = other.x_up;
            x_down  = other.x_down;
        }
};

struct LineCmpY {
    bool operator()(const LineSeg& lhs, const LineSeg& rhs) const { 
        return lhs.start.y < rhs.start.y;
    }
};

set<i64> x_values;
unordered_map<i64, vector<LineSeg>> h_starts;
unordered_map<i64, vector<LineSeg>> h_ends;
unordered_map<i64, vector<LineSeg>> vsegments;
size_t total_area = 0;
vector<size_t> areas;

void sweep() {
    set<LineSeg, LineCmpY> hactive; 
    for (auto x : x_values) {
        // Process verticals
        for (auto &vl : vsegments[x]) {
            if (hactive.empty()) break;
            auto ub = hactive.lower_bound({{0,vl.start.y}, {0,0}});
            auto lb = ub;
            ub++;
            for (; ub != hactive.end() && ub->end.y <= vl.end.y; lb++, ub++) {
                i64 len = max(abs(vl.start.x - ub->x_down), abs(vl.start.x - lb->x_up));
                size_t area = len*(ub->start.y - lb->start.y);
                if (len == 0) continue;
                areas.push_back(area);
                total_area += area;
                const_cast<LineSeg&>(*lb).x_up = vl.start.x;
                const_cast<LineSeg&>(*ub).x_down = vl.start.x;
            }
        }

        // Remove all ending
        for (auto &hl : h_ends[x]) {
            hactive.erase(hl);
        }

        //insert all starting
        auto hint_itr = hactive.begin();
        for (auto &hl : h_starts[x]) {
            hint_itr = hactive.emplace_hint(hint_itr, hl);
        }
    }
}

int main() {
    areas.reserve(200000);
    i64 m;
    fastscan(m);

    while (m--) {
        Point a, b;
        fastscan(a.x); fastscan(a.y); fastscan(b.x); fastscan(b.y);

        Point start = a;
        Point end = b;
        if (b.x < a.x) {
            start = b;
            end = a;
        } else if (b.x == a.x && b.y < a.y) {
            start = b;
            end = a;
        }
        LineSeg ls = LineSeg(start, end);

        x_values.insert(start.x);

        // vertical
        if (start.x == end.x) {
            vsegments[start.x].push_back(ls);
        }

        // horizontal
        if (start.y == end.y) {
            h_starts[start.x].push_back(ls);
            h_ends[end.x].push_back(ls);
        }
    }
    sweep();

    sort(areas.rbegin(), areas.rend());
    cout << setprecision(16);
    for (auto &a : areas) {
        cout << ((double)a/(double)total_area) << "\n";
    }

    return 0;
}
