#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H, W;
    cin >> N >> H >> W;

    vector<bitset<100>> bits(W*H);
    
    for(int i = 0; i < N; i++) {
        for(int h = 0; h < H; h++) {
            for(int w = 0; w < W; w++) {
                char c;
                cin >> c;
                if(c == '*')
                    bits[h*W+w][i] = 1;
            }
        }
    }

    unordered_set<bitset<100>> s;
    for(int i = 0; i < W*H; i++) {
        s.insert(bits[i]);
    }

    cout << s.size() << endl;

    return 0;
}
