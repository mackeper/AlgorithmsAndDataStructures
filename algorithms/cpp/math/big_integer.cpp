#include "big_integer.hpp"

/** 
 *  Big Integer
 *  Author: Marcus Östling
 */

/*
 *  Member functions
 */

BigInteger::BigInteger(int n) {
    if(n < 0) {
        this->negative_ = true;
        n *= -1;
    } else {
        this->negative_ = false;
    }
    this->values_.resize(1, n);
}

BigInteger::BigInteger(const BigInteger &other) {
    this->negative_ = other.negative_;
    this->values_ = std::vector<unsigned int>(other.values_);
}


BigInteger::BigInteger() {
    this->negative_ = false;
}

void BigInteger::RemovePrefixZeroes() {
    while(this->size() > 1 && (*this)[this->size()-1] == 0)
        this->values_.pop_back();
}

size_t BigInteger::size() const {
    return this->values_.size();
}

void BigInteger::push_back(unsigned int value) {
    this->values_.push_back(value);
}

unsigned int& BigInteger::operator[](const unsigned int index) {
    return values_[index];
}

unsigned int BigInteger::operator[](const unsigned int index) const {
    return values_[index];
}

void BigInteger::operator+=(const BigInteger &rhs) {
    //2 positive
    BigInteger &lhs = *this;
    BigInteger res;
    unsigned int carry = 0;
    unsigned int largest = std::max(lhs.size(), rhs.size());
    for(unsigned int i = 0; i < largest; i++) {
        if(i < lhs.size()) carry += lhs[i];
        if(i < rhs.size()) carry += rhs[i];
        res.push_back(carry%base);
        carry /= base;
    }
    if(carry) 
        res.push_back(carry);
    res.RemovePrefixZeroes();
    this->values_ = std::move(res.values_);
}

void BigInteger::operator+=(const int rhs) {
    BigInteger tmp(rhs);
    (*this) += tmp;
}

void BigInteger::operator*=(const BigInteger &rhs) {
    (*this).RemovePrefixZeroes();
    BigInteger res;
    res.values_.assign(this->size() + rhs.size(), 0);

    for (int a = 0; a < (int)this->size(); a++) {
        int carry = 0;
        for (int b = 0; b < (int)rhs.size() || carry > 0; b++) {
            int s = res[a+b] + carry;
            if (b < (int)rhs.size())
                s += (*this)[a]*rhs[b];
            res[a+b] = s % this->base;
            carry = s / this->base;
        }
    }
    res.RemovePrefixZeroes();
    this->values_ = res.values_;
}

void BigInteger::operator*=(const int rhs) {
    BigInteger tmp(rhs);
    (*this) *= tmp;
}

void BigInteger::operator/=(const BigInteger &rhs) {
    //TODO
}

void BigInteger::operator/=(const int rhs){
    (*this).RemovePrefixZeroes();
    if(BigInteger(rhs) > *(this)) {
        (*this) = BigInteger(0);
        return;
    }
    BigInteger res;
    res.values_.resize(this->size(), 0);
    int y = 0;
    for(int i = this->size()-1; i >= 0; --i){
        y = y * this->base + (*this)[i];
        res[i] = y / rhs;
        y = y % rhs;
    }

    res.RemovePrefixZeroes();
    this->values_ = res.values_;
}

void BigInteger::operator=(const BigInteger &rhs) {
    this->negative_ = rhs.negative_;
    this->values_ = std::vector<unsigned int>(rhs.values_);
}

bool BigInteger::operator<(const BigInteger &rhs) const {
    if(this->size() != rhs.size()) return this->size() < rhs.size();
    for(int i = this->size()-1; i >= 0; i--) {
        if((*this)[i] != rhs[i]) return (*this)[i] < rhs[i];
    }
    return false;
}

bool BigInteger::operator>(const BigInteger &rhs) const {
    return (rhs < (*this));
}

bool BigInteger::operator==(const BigInteger &rhs) const {
    return (!((*this) < rhs) && !(rhs < (*this)));
}

bool BigInteger::operator!=(const BigInteger &rhs) const {
    return !((*this) == rhs);
}

/*
 *  Non-member functions
 */

std::ostream& operator<<(std::ostream& os, const BigInteger &b_int) {
    os << b_int[b_int.size()-1];
    for(int i = b_int.size()-2; i >= 0; i--) {
        os << std::setfill('0') << std::setw(4) << b_int[i];
    }
    return os;
}; 

BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs) {
    BigInteger tmp(lhs);
    tmp += rhs;
    return tmp;
}

BigInteger operator*(const BigInteger &lhs, const BigInteger &rhs) {
    BigInteger tmp(lhs);
    tmp *= rhs;
    return tmp;
}

