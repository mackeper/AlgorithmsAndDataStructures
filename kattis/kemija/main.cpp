#include <bits/stdc++.h>
#include "lin_eq_solver.hpp"

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
//#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void constructA(vector<vector<double>> &A) {
    int n = sz(A);
    rep(i, 0, n) {
        A[i][(i-1+n)%n] = 1;
        A[i][i] = 1;
        A[i][(i+1)%n] = 1;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<double> b(n);
    vector<double> x;
    trav(i, b) {
        cin >> i;
    }
    vector<double> b2(b);
    vector<vector<double>> A(n, vector<double>(n, 0));
    constructA(A);

    int res = popup::linear_solve(A, b2, x);

    trav(i, b2) {
        cout << i << "\n";
    }

    return 0;
}
