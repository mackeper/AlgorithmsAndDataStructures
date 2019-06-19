#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include "rational.hpp"

#define EPS 10e-5
using namespace std;

void pRat(popup::Rational<int64_t> r) {
   // printf("%d / %d\n", r.numenator(), r.denominator());
}

void continuedFractions(popup::Rational<int64_t> r, vector<int64_t> &pqs) {
  //printf("-----\n");
  int64_t i_part = (int64_t)((r.numenator() / r.denominator())+EPS);
  popup::Rational<int64_t> tmp(i_part, 1);
  popup::Rational<int64_t> tmp2(1, 1);
  //pRat(r);
  //pRat(tmp);
  //pRat(r-tmp);
  pqs.push_back(i_part);
  if(abs((r-tmp).numenator()) > EPS)
    continuedFractions(tmp2/(r - tmp), pqs);
}

popup::Rational<int64_t> rationalNumber(const vector<int64_t> &pqs, size_t index) {
  if(index == 0 && pqs.size() == 1)
    return popup::Rational<int64_t>(pqs[index], 1);
  if(index+1 == pqs.size())
    return popup::Rational<int64_t>(1, pqs[index]);
  if(index == 0) {
    popup::Rational<int64_t> tmp(pqs[index], 1);
    return tmp + rationalNumber(pqs, index+1);
  }
  return popup::Rational<int64_t>(1,1)/(popup::Rational<int64_t>(pqs[index], 1)+rationalNumber(pqs, index+1));
}

int main() {
  /*
  popup::Rational<int> ri1(349,200);
  popup::Rational<int> ri2(3,2);
  vector<int> sumv;
  continuedFractions(ri1+ri2, sumv);
  for(auto pq : sumv)
    printf("%d ", pq);
  printf("\n");
  */int n1, n2;
  scanf("%d %d", &n1, &n2);

  vector<int64_t> pqs1(n1);
  vector<int64_t> pqs2(n2);

  for(int i = 0; i < n1; i++)
    scanf("%li", &pqs1[i]);

  for(int i = 0; i < n2; i++)
    scanf("%li", &pqs2[i]);

  popup::Rational<int64_t> ri1 = rationalNumber(pqs1, 0);
 // pRat(ri1);

  popup::Rational<int64_t> ri2 = rationalNumber(pqs2, 0);
 // pRat(ri2);

  // sum
  vector<int64_t> sumv;
  continuedFractions(ri1 + ri2, sumv);
  for(auto pq : sumv)
    printf("%li ", pq);
  printf("\n");

  // diff
  vector<int64_t> diffv;
  continuedFractions(ri1-ri2, diffv);
  for(auto pq : diffv)
    printf("%li ", pq);
  printf("\n");

  // product
  vector<int64_t> prodv;
  continuedFractions(ri1*ri2, prodv);
  for(auto pq : prodv)
    printf("%li ", pq);
  printf("\n");

  // quotient
  vector<int64_t> quotv;
  continuedFractions(ri1/ri2, quotv);
  for(auto pq : quotv)
    printf("%li ", pq);
  printf("\n");
  return 0;
}
