#include <iostream>
#include "big_integer.hpp"

using namespace std;

int main() {
    BigInteger b_int1(0);
    BigInteger b_int2(1000000000);
    BigInteger b_int3(5);
    for(int i = 0; i < 11; i++) {
        b_int1 += b_int2;
        cout << b_int1 << endl;
    }

    b_int1 = b_int3;
    cout << b_int1 << endl;
    BigInteger b_int4(3000000);
    BigInteger b_int5(4);
    b_int5 *= b_int4;
    cout << b_int5 << endl;

}
