#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

int main() {
  int n;

  cin >> n;
  string str;
  for (int i = 0; i < n; i++) {
    stack<char> s;
    bool no = false;
    cin >> str;
    for (int j = 0; j < str.size(); j++) {
      if (str[j] == '[')
        s.push(']');
      else if (str[j] == '(')
        s.push(')');
      else if (str[j] == '{')
        s.push('}');
      else if (!s.empty() && s.top() == str[j])
        s.pop();
      else {
        cout << "NO\n";
        no = true;
        break;
      }
    }

    if (!no && s.empty())
      cout << "YES\n";
    else if (!no)
      cout << "NO\n";
  }
}
