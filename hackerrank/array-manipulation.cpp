#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long int> arr(n+2,0);
    int a, b, val;
    for(int i = 0; i < m; i++) 
    {
        cin >> a >> b >> val;
        arr[a] += val;
        arr[b+1] -= val;
    }

    long int sum = 0;
    long int max = 0;
    for (int i = 0; i <= n; i++) {
        sum += arr[i];
        if(sum > max) {
            max = sum;
        }
    }

    cout << max << endl;
}
