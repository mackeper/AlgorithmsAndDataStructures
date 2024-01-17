#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    auto l = new int[N];
    for (auto i = 0; i < N; i++)
        cin >> l[i];
    for (auto i = N-1; i >=0; i--)
        cout << l[i] << "\n";

    return 0;
}