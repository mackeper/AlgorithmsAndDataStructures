#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

// idx <= 16 digits (10^15)
// sum <= 135
// tight: true or false
ll mem[16][136][2];

void getDigits(ll number, vi &digits) {
  while(number) {
    digits.push_back((int)(number%10));
    number /= 10;
  }
}

/** 
 *  idx: current index
 *  sum: current sum
 *  goalSum: the sum we are looking for
 *  digits: the digits of the number
 */
ll digitSum(int idx, ll sum, ll goalSum, int tight, vi &digits) {
  if (sum == goalSum) {
    return 1;
  } else if (idx < 0 || sum > goalSum) {
    return 0;
  } else if(mem[idx][sum][tight] != -1 && tight != 1) {
    return mem[idx][sum][tight];
  }
  
  ll res = 0;
  size_t k = tight ? digits[idx] : 9;
  for (size_t i = 0; i <= k; i++) {
    int newtight = (size_t)digits[idx] == i ? tight : 0;
    res += digitSum(idx-1, sum+i, goalSum, newtight, digits);
  }

  mem[idx][sum][tight] = res;
  return mem[idx][sum][tight];
}

// Find the smallest number in the interval
ll nextDigitSum(vi &aDigits, ll goalSum) {
  ll sum = 0;
  trav(i, aDigits)
    sum += i;

  if(aDigits.size() == 0) {
    aDigits.push_back(1);
    sum++;
  }

  size_t idx = 0;
  while(sum < goalSum) {
    if(idx < aDigits.size() && aDigits[idx] < 9) {
      aDigits[idx]++;
      sum++;
    } else {
      idx++;
      if(idx > aDigits.size()-1) {
        aDigits.push_back(1);
        sum++;
      }
    }
  }

  ll next = 0;
  for(int i = (int)aDigits.size(); i >= 0; i--) {
    next = (next*10)+aDigits[i];
  }
  return next;

}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);

  // interval [a,b]
  ll a, b, sum;
  cin >> a >> b >> sum;
  memset(mem, -1, sizeof(mem));

  // Solve the problem for [0,a) and [0, b+1)
  vi aDigits; getDigits(a-1, aDigits);
  vi bDigits; getDigits(b, bDigits);
  ll bsum = digitSum((int)bDigits.size()-1, 0, sum, 1, bDigits);
  ll asum = digitSum((int)aDigits.size()-1, 0, sum, 1, aDigits);

  // Find the smallest of those numbers
  vi aDigits2; getDigits(a, aDigits2);
  ll next = nextDigitSum(aDigits2, sum);

  // The solution will then be [0, b+1) - [0, a)
  printf("%lld\n%lld\n", bsum - asum, next);
  return 0;
}
