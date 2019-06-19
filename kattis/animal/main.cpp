#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

const unsigned long long MOD_PRIME1 = 922337220451ULL;
const unsigned long long MOD_PRIME2 = 32416190071ULL;
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

unsigned long long res = 0;
unordered_set<u64> hashes1;
//unordered_set<u64> hashes2;

void parser(bool alice)
{
    vector<u64> classes1;
    //vector<u64> classes2;
    u64 current_val = -1;
    u64 id = -1;
    vector<u64> stk;
    for (char c = (char)getchar_unlocked(); c != '\n'; c = (char)getchar_unlocked()) {
        if (c == '(') {
            classes1.emplace_back();
            //classes2.emplace_back();
            id++;
            stk.push_back(id);
        } else if (c == ')') {
            if (current_val != (u64)-1) {
                for (u64 i : stk) {
                    classes1[i] += current_val*current_val + current_val * current_val * current_val;
                    //classes2[i] += current_val*(current_val+1);
                }
                current_val = -1;
            }
            if (alice) {
               hashes1.insert(classes1[stk.back()]);     
               //hashes2.insert(classes2[stk.back()]);     
            } else if (!alice //Hash of stk.back() is in both hashes1 and hashes2
                && hashes1.find((classes1[stk.back()])) != hashes1.end()
                //&& hashes2.find((classes2[stk.back()])) != hashes2.end()
                ) {
               res++;
            }
            stk.pop_back();
        } else if (c == ',') {
            if (current_val != (u64)-1) {
                for (u64 i : stk) {
                    classes1[i] += current_val*current_val + current_val * current_val * current_val;
                    //classes2[i] += current_val*(current_val+1);
                }
                current_val = -1;
            }
        } else {
            if (current_val == (u64)-1) {
                current_val = c-'0';
            } else {
                current_val = current_val * 10 + c-'0';
            }
       }
    }
}

int main() {
    u64 n;
    cin >> n;
    getchar_unlocked();

    parser(true);
    parser(false);
    res += n;

    cout << res << endl;

    return 0;
}

