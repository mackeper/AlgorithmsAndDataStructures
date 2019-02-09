#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  char letter;
  
  bool read = true;
  while(cin >> letter) {
    if(read) {
      printf("%c", letter); read = false;
    } else if(letter == '-')
      read = true;
  }
  
  return 0;
}
