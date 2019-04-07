#ifndef BIG_INTEGER_
#define BIG_INTEGER_

#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>

/** 
 *  Big Integer
 *  Author: Marcus Östling
 */

class BigInteger {
    // Base must be haft of the size of the type.
    // Change setw in operator<< if changed ... bad code
    const unsigned int base = (unsigned int)(10000);
    std::vector<unsigned int> values_;
    bool negative_;

    void push_back(unsigned int value);

public:
    BigInteger(int n);
    BigInteger(const BigInteger &other);
    BigInteger();

    void RemovePrefixZeroes();
    size_t size() const;
    unsigned int  operator[](const unsigned int index) const;
    unsigned int& operator[](const unsigned int index);

    // Assign
    void operator+=(const BigInteger &rhs);
    void operator*=(const BigInteger &rhs);
    void operator/=(const BigInteger &rhs);
    void operator= (const BigInteger &rhs);
    void operator+=(const int rhs);
    void operator*=(const int rhs);
    void operator/=(const int rhs);

    // Compare
    bool operator< (const BigInteger &rhs) const;
    bool operator> (const BigInteger &rhs) const;
    bool operator==(const BigInteger &rhs) const;
    bool operator!=(const BigInteger &rhs) const;
    
};

std::ostream& operator<<(std::ostream& os, const BigInteger &b_int);
BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs);
BigInteger operator*(const BigInteger &lhs, const BigInteger &rhs);
//BigInteger operator/(const BigInteger &lhs, const unsigned int rhs);

#endif // BIG_INTEGER_
