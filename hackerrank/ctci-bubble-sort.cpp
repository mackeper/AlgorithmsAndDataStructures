#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<string> split_string(string);

// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    int swaps = 0;
    for (int i = 0; i < a.size(); i++) {

      for (int j = 0; j < a.size() - 1; j++) {
        // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swaps++;
            }
        }
    }
    printf("Array is sorted in %d swaps.\n", swaps);
    printf("First Element: %d\n", a[0]);
    printf("Last Element: %d\n", a[a.size() - 1]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    countSwaps(a);

    return 0;
}
