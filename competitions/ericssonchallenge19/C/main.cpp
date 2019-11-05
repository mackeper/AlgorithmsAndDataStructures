#include <bits/stdc++.h>
using namespace std;

int count_bits(unsigned int v) {
	int res = 0;
	for (unsigned int i = 0; i < 32; i++) {
		res += v & 1;
		v >>= 1;
	}
	return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
	
	int n;
cin >> n;
	while(n--) {
		int value = 0;
		int max_bits = 0;
		string s;
		cin >> s;
		for (char c : s) {
			value = value*10 + (c - 48);
			if(count_bits(value) > max_bits) {
				max_bits = count_bits(value);
}
		}
		cout << max_bits << endl;
		
}

    return 0;
}
