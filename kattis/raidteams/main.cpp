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
typedef tuple<string, i64, i64, i64> player;

class Player {
    public:
    string n;
    i64 a, b, c;
    Player() {};
    Player(string _n, i64 _a, i64 _b, i64 _c) : n(_n), a(_a), b(_b), c(_c) {};
};

int main() {
    auto cmpa = [](Player* a, Player* b) {
        return a->a == b->a ? a->n.compare(b->n) < 0 :  a->a > b->a;
    };
    auto cmpb = [](Player* a, Player* b) {
        return a->b == b->b ? a->n.compare(b->n) < 0 : a->b > b->b;
    };
    auto cmpc = [](Player* a, Player* b) {
        return a->c == b->c ? a->n.compare(b->n) < 0 : a->c > b->c;
    };
    set<Player*, decltype(cmpa)> sa(cmpa);
    set<Player*, decltype(cmpb)> sb(cmpb);
    set<Player*, decltype(cmpc)> sc(cmpc);
    unordered_set<Player*> used;
    int N;
    cin >> N;
    auto n = N;
    while(n--) {
        
        auto p = new Player();
        cin >> p->n >> p->a >> p->b >> p->c;
        sa.emplace(p);
        sb.emplace(p);
        sc.emplace(p);
    }

    auto pai = sa.begin();
    auto pbi = sb.begin();
    auto pci = sc.begin();
    while(N - used.size() >= 3) {
        // a
        while(used.find(*pai) != used.end() && pai != sa.end()) {
            pai++;
        }
        used.emplace(*pai);

        // b
        while(used.find(*pbi) != used.end() && pbi != sb.end()) {
            pbi++;
        }
        used.emplace(*pbi);

        // c
        while(used.find(*pci) != used.end() && pci != sc.end()) {
            pci++;
        }
        used.emplace(*pci);

        auto a = *pai;
        auto b = *pbi;
        auto c = *pci;

        if (a->n > b->n)
            swap(a, b);
        if (a->n > c->n)
            swap(a, c);
        if (b->n > c->n)
            swap(b, c);
        cout << a->n << " " << b->n << " " << c->n << "\n";
    }

    return 0;
}