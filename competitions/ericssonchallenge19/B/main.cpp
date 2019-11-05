#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	while(n--) {
		vector<char> a = {'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k','l','m','n',
			'o','p','q','r', 's', 't','u','v','w','x','y','z'};
	string s;
	getline(cin, s);
	for (char c : s) {
		int i = 0;
		for (char c2 : a) {
			if (c2 == tolower(c)) {
				a.erase(a.begin()+i);
				break;
			}
			i++;
		}
			
	}
	if (a.empty()) {
		cout << "pangram\n";
} else {
	cout << "missing ";
	for(char c : a) {
		cout << c;
	}
		cout << endl;
}
}

    return 0;
}
