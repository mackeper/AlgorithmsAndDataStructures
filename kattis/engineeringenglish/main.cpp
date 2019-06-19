#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream> //stringstream ss(s);
#include <algorithm>
#define NDEBUG
#include <cassert>

using namespace std;

unordered_map<string, bool> mem;

int main() {
    string line;
    assert(1==0);
    while(getline(cin, line)) {
        string s;
        stringstream ss(line);
        while(ss >> s) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            if(mem.find(s) != mem.end()) {
                cout << ". ";
            } else {
                mem[s] = true;
                cout << s << " ";
            }
        }
        cout << "\n";
    }
}
