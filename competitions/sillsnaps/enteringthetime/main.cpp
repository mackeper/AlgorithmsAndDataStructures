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

int mem[10][10][10][10];
vector<int> from[10][10][10][10];
int from_set[10][10][10][10];
string val[10][10][10][10];

void printc(vector<int> &clock) {
    printf("%d%d:%d%d\n", clock[0], clock[1],
            clock[2], clock[3]);
}

string ctos(vector<int> &clock) {
    string s = 
        to_string(clock[0]) + "" + to_string(clock[1]) +
        ":" + to_string(clock[2]) + "" + to_string(clock[3]);
    return s;

}

bool isInvalid(vector<int> &clock) {
    return clock[0] > 2 || (clock[0] == 2 && clock[1] > 3)
        || clock[2] > 5;
}

bool equals(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool operator==(vector<int> &a, vector<int> &b) {
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

int mod(int &n) {
    return n = (n + 10) % 10;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(mem, 0, sizeof(mem));
    memset(from_set, 0, sizeof(from_set));

    vector<int> setto(4);
    vector<int> current(4);
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        char c;
        cin >> c;
        if (i == 2) continue;
        setto[cnt] = (int)c - 48;
        cnt++;
    }
    cnt = 0;
    for (int i = 0; i < 5; i++) {
        char c;
        cin >> c;
        if (i == 2) continue;
        current[cnt] = (int)c - 48;
        cnt++;
    }

    vector<int> start = setto;
    queue<vector<int>> q;
    vector<int> res;
    q.push(setto);
    int nres = 0;
    while(!q.empty()) {
        nres++;
        vector<int> t = q.front();
        q.pop();
        if (mem[t[0]][t[1]][t[2]][t[3]] == 1) continue;
        if (isInvalid(t)) continue;

        if (equals(t, current)) {
            res = t;
            break;
        }
        mem[t[0]][t[1]][t[2]][t[3]] = 1;


        for (int i = 0; i < 4; i++) {
            vector<int> r(t);
            r[i]++;
            mod(r[i]);
            if (!isInvalid(r) && !mem[r[0]][r[1]][r[2]][r[3]]) {
                q.push(r);
                from    [r[0]][r[1]][r[2]][r[3]] = t;
                from_set[r[0]][r[1]][r[2]][r[3]] = 1;
            }
            r = t;
            r[i]--;
            mod(r[i]);
            if (!isInvalid(r) && !mem[r[0]][r[1]][r[2]][r[3]]) {
                q.push(r);
                from    [r[0]][r[1]][r[2]][r[3]] = t;
                from_set[r[0]][r[1]][r[2]][r[3]] = 1;
            }
        }
    }

    if (nres == 1) {
        cout << "1\n";
        cout << ctos(res) << endl;
        return 0;
    }

    vector<string> result;
    result.push_back(ctos(res));
    vector<int> t = from[res[0]][res[1]][res[2]][res[3]];
    while(!t.empty() && 
            (t[0] != start[0] || t[1] != start[1] || t[2] != start[2] || t[3] != start[3])) {
        result.push_back(ctos(t));
        vector<int> tmp(t);
        t = from[t[0]][t[1]][t[2]][t[3]];
    }

    result.push_back(ctos(start));
    reverse(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto s : result)
        cout << s << endl;

    return 0;
}
