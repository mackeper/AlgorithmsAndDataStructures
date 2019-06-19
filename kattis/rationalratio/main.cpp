#include <cstdio>
#include <iostream>
#include <cmath>
#include "rational.hpp"
#include <cassert>

using namespace std;

int main() {
  int64_t integer;
  string s_fraction;
  int64_t repeating;

  scanf("%li.", &integer);
  cin >> s_fraction;
  scanf("%li", &repeating);


  // Get the value of the fraction
  int64_t fraction = 0;
  int64_t fraction_length = s_fraction.size();
  for(int i = fraction_length-1; i >= 0; i--) {
      fraction += ((int)s_fraction[fraction_length-1-i]-48)*pow(10, i);
  }

  //Find two numbers with the same decimal endings
  int64_t num_part1 = integer*pow(10, fraction_length) + fraction;
  int64_t num_minus = integer*pow(10, fraction_length - repeating) + fraction/pow(10, repeating);
  int64_t num = num_part1 - num_minus;
  int64_t den = pow(10, fraction_length)-pow(10, fraction_length-repeating);

  popup::Rational<int64_t> r(num, den);
  printf("%li/%li\n", r.numenator(), r.denominator());

  return 0;
}
