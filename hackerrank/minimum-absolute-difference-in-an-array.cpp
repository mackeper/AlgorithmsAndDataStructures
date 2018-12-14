#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int diff = INT_MAX;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n-1; i++) {
        diff = min(abs(arr[i]-arr[i+1]), diff);
    }

    cout << diff << "\n";

    return 0;
}
