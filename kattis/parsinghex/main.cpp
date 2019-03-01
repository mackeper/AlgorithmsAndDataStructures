#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool isHexa(char c) {
    return (('0' <= c && c <= '9') || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f'));
}

void out_hexa(string &hexa) {
    cout << hexa << " ";
    ll value = 0;
    rep(i, 2, hexa.size()) {
        ll v;
        if('0' <= hexa[i] && hexa[i] <= '9')
            v = hexa[i] - '0';
        else if('A' <= hexa[i] && hexa[i] <= 'F')
            v = 10 + hexa[i] - 'A';
        else
            v = 10 + hexa[i] - 'a';
        value += v * pow(16,hexa.size()-i-1);
    }
    cout << value << endl;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    while(cin >> str) {
        char lastchar = ' ';
        bool in_hex;
        string hexa = "";
        rep(i, 0, str.size()) {
            if(lastchar == '0' && (str[i] == 'x' || str[i] == 'X')) {
                hexa = "0";
                hexa += str[i];
                in_hex = true;
            } else if(in_hex && isHexa(str[i])) {
                hexa += str[i];
            } else if(in_hex && hexa != "") {
                in_hex = false;
                out_hexa(hexa);
                hexa = "";
            }
            lastchar = str[i];
        }
        if(in_hex && hexa != "") {
            in_hex = false;
            out_hexa(hexa);
            hexa = "";
        }
    }


    return 0;
}
