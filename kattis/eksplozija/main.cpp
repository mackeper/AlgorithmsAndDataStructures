#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9
#define BOARD_SIZE 16
#define BOARD_SIDE 4

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string str; 
string explo;
stack<int> stk;
unordered_map<int, int> jump;
int exploaded_chars = 0;

void find_exps()
{ 
    int state = 0;
    int text_idx = 0;
    while(text_idx < (int)str.size()) {
        if(jump.find(text_idx) != jump.end()) {
            text_idx = jump[text_idx];
            continue;
        }
        if(str[text_idx] == explo[0]) {
            stk.push(text_idx);
        }
        if(str[text_idx] == explo[state]) {
            state++;
        } else {
            state = 0;
            if(str[text_idx] == explo[state]) {
                state++;
            }
        }

        if(state == (int)explo.size()) {
            int expstart = stk.top();
            jump[expstart] = text_idx+1;
            stk.pop();
            state = 0;
            if(!stk.empty()) {
                text_idx = stk.top();
                stk.pop();
            }
            exploaded_chars += (int)explo.size();
            continue;
        }

        text_idx++;
    }

    if(exploaded_chars < (int)str.size()) {
        int text_idx = 0;
        while(text_idx < (int)str.size()) {
            if(jump.find(text_idx) != jump.end()) {
                text_idx = jump[text_idx];
                continue;
            }
            cout << str[text_idx];
            text_idx++;
        }
        cout << "\n";
    } else {
        cout << "FRULA\n";
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> str >> explo;
    find_exps();

    return 0;
}
