#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    //For faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(b-a-1,c-b-1) << "\n";

    return 0;
}
