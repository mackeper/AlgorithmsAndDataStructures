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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<int> idxs(n+m+1);
    iota(idxs.begin(), idxs.end(), 0);
    vector<double> prob(n+m+1, 0);
    for (double x = 1; x <= (double)n; x++) {
        for (double y = 1; y <= (double)m; y++) {
            double d = (1/(double)n)*(1/(double)m);
            prob[(int)x+(int)y] += d;
        }
    }

    sort(idxs.begin(), idxs.end(), [&prob](const int a, const int b) {
        if(abs(prob[a] - prob[b]) < EPS)
            return a < b;
        return prob[a] > prob[b];        
    });
    double p = prob[idxs[0]];
    cout << idxs[0] << endl;
    int idx = 1;
    while(abs((prob[idxs[idx]] - p)) < EPS) {
        cout << idxs[idx] << endl;
        idx++;
    }

    return 0;
}
