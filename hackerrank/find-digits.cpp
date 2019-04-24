#include <bits/stdc++.h>

using namespace std;

int findDigits(int n) {
    int res = 0;
    int x = n;
    while (x > 0) {
      if ((x % 10) != 0 && n % (x % 10) == 0)
        res++;
      x /= 10;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << findDigits(n)<< "\n";
    }
    return 0;
}
