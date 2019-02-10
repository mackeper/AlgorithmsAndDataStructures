#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //For faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long double x1, x2, y1, y2, p;
    for(cin >> x1; x1 != 0; cin >> x1) {
        cin >> y1 >> x2 >> y2 >> p;
        cout << pow(pow(abs(x1-x2), p) + pow( abs(y1-y2), p), 1/p) << "\n";
    }

    return 0;
}
