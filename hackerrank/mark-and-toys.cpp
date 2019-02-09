#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int i = 0;
    int toys = 0;
    while(m > 0) {
        if(m >= v[i])
        {
            toys++;
            m -= v[i];
            i++;
        }
        else {
            m = 0;
        }
    }

    cout << toys << endl;
    return 0;
}
