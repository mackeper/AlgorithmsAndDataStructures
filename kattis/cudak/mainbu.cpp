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
pll mem[16][136][2];

void getDigits(ll number, vll &digits) {
  while(number) {
    digits.push_back(number%10);
    number /= 10;
  }
}

/** 
 *  idx: current index
 *  sum: current sum
 *  goalSum: the sum we are looking for
 *  digits: the digits of the number
 */
pll digitSum(ll idx, ll sum, ll goalSum, int tight, vll &digits, ll used_number, ll a) {
  //printf("idx: %lld used: %lld\n", idx, used_number);
  if (sum == goalSum) {
    //printf("used: %lld\n", used_number);
    return make_pair(1, used_number);
  } else if (idx < 0) {
    return make_pair(0, numeric_limits<ll>::max());
  } else if(mem[idx][sum][tight].first != -1 && tight != 1) {
    
    pll res = mem[idx][sum][tight];
    if(res.first > 0) 
      printf("idx: %lld used: %lld mem: %lld test:%lld\n",idx, used_number, res.second,
          used_number*(ll)pow(10, idx+1) + res.second - (res.second/(ll)pow(10,idx+1))*(ll)pow(10,idx+1) );
    return make_pair(res.first, a <= used_number ? used_number : numeric_limits<ll>::max());
  }
  
  ll num_sums = 0;
  ll smallest_used_number = numeric_limits<ll>::max();
  size_t k = tight ? digits[idx] : 9;
  for (size_t i = 0; i <= k; i++) {
    int newTight = (size_t)digits[idx] == i ? tight : 0;
    pll res = digitSum(idx-1, sum+i, goalSum, newTight, digits, used_number*10+i, a);
    num_sums += res.first;
    smallest_used_number = min(smallest_used_number, res.second);
  }

  mem[idx][sum][tight] = make_pair(num_sums, smallest_used_number);
  return mem[idx][sum][tight];
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
  vll aDigits; getDigits(a-1, aDigits);
  vll bDigits; getDigits(b, bDigits);
  
  pll bsum = digitSum(bDigits.size()-1, 0, sum, 1, bDigits, 0, a);
  pll asum = digitSum(aDigits.size()-1, 0, sum, 1, aDigits, 0, a);

  // The solution will then be [0, b+1) - [0, a)
  printf("%lld\n%lld", bsum.first - asum.first, min(asum.second, bsum.second));

  return 0;
}
