#include <stdio.h>
using namespace std;

namespace input {

void scanint(int *x) {
    int c;
    *x = getchar_unlocked() - 48;
    while (48 <= (c = getchar_unlocked())) *x = (*x<<3) + (*x<<1) + c - 48;
}

void scanlong(unsigned long long *x) {
    unsigned long long c;
    *x = getchar_unlocked() - 48;
    while (48 <= (c = getchar_unlocked())) *x = (*x<<3) + (*x<<1) + c - 48;
}

void scanstr(char *buf, size_t len) {
  for(size_t i = 0; i < len; i++)
    buf[i] = (char)getchar_unlocked();
}

} // namespace input
