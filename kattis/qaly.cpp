#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  double qaly = 0;
  double x, y;
  while(n-- > 0) {
    scanf("%lf %lf", &q, &y);
    qaly += q*y;
  }

  printf("%lf\n", qaly);
  
  return 0;
}
