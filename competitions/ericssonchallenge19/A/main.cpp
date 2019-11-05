#include <bits/stdc++.h>
using namespace std;

int isdig(string s) {
	int res = 0;
	for(char c : s) {
		//cout << c << " " << (int)c << endl;
		if (48 > c || c > 57) {
			return -1;
		}
		res = res*10 + (c - 48);
	}
	//cout << res << endl;
	return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	map<int, string> t;
	for (int i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		//cout << s1 << endl;
		if (isdig(s1) == -1) {
			//cout << "s1 string" << endl;
			t.insert({isdig(s2)*2, s1});	
		} else {
			//cout << "s1 not string" << endl;
			t.insert({isdig(s1), s2});	
		}
	}
	for (auto p : t) {
		cout << p.second << endl;
	}
    return 0;
}
