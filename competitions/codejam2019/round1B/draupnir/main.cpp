#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const unsigned long long MOD_PRIME = 922337220451ULL;
const unsigned long long ONE_PRIME = 16069ULL;
const unsigned long long INV_PRIME = 184249329619ULL;

//#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

typedef long long i64;
typedef unsigned long long u64;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <limits>
#include <algorithm>
#include <numeric>

#define EPS 1e-12

namespace popup {

  enum SOLTUION_TYPE {
                 NONE = 0,
                 ONE = 1,
                 MULTIPLE = 2
  };

  /**
   *  Solves a linear equation given a matrix A and a vector b.
   *  Returns NONE if there does not exist a solution.
   *          One if the exists a solution.
   *          MULTIPLE if the exists multiple solutions.
   *
   *  The matrix a and the vector b will not be perserved.
   *  If ONE was returned the solution can be found in ans.
   */
  template<typename T>
  SOLTUION_TYPE linear_solve(std::vector<std::vector<T>>& a,
                   std::vector<T>& b,
                   std::vector<T>& ans
                   ) {

    const auto num_rows = a.size();
    const auto num_columns = a[0].size();

    size_t pivot_row, pivot_column; // h, k
    pivot_row = pivot_column = 0;
    int rank = 0;

    // Gaussian elimination to row echolon form
    while (pivot_row < num_rows && pivot_column < num_columns) {
      size_t row_max = pivot_row;
      T max_found = std::fabs(a[pivot_row][pivot_column]);

      for (size_t i = pivot_row + 1; i < num_rows; i++) {
        auto value = std::fabs(a[i][pivot_column]);
        if (value > max_found) {
          row_max = i;
          max_found = value;
        }
      }

      if (std::fabs(a[row_max][pivot_column]) < EPS) {
        pivot_column++;
        continue;
      }

      std::swap(a[pivot_row], a[row_max]);
      std::swap(b[pivot_row], b[row_max]);

      for (int i = pivot_row + 1; i < num_rows; i++) {
        const auto factor = a[i][pivot_column] / a[pivot_row][pivot_column];
        a[i][pivot_column] = 0;

        for (int j = pivot_column + 1; j < num_columns; j++) {
          a[i][j] -= factor * a[pivot_row][j];
        }
        b[i] -= factor * b[pivot_row];
      }

      pivot_row++;
      pivot_column++;

      rank++;
    }
    
    // Check if a solution exists.
    for (int row = num_rows-1; row >= rank; row--) {
      T sum = 0;
      for (int i = 0; i < num_columns; i++)
        sum += a[row][i];
      //      std::cout << "Sum: " << sum << "\n";
      if (std::fabs(sum - b[row]) > EPS) {
        return NONE;
      }
    }

    // Corrects the b values as it goes to correct
    // Back substitution (but only for b)
    ans.assign(rank, 0);
    for (int row = rank -1; row >= 0; row--) {
      b[row] /= a[row][row];
      ans[row] = b[row];
      for (int j = row - 1; j >= 0; j--) {
        b[j] -= a[j][row] * b[row];
      }
    }

    if (rank < num_rows) {
      return MULTIPLE;
    } else {
      return ONE;
    }
  }

}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    //cin.exceptions(cin.failbit);
    

    int T = 1, W;
    cin >> T >> W;
    for (int t = 1; t <= T; t++) {
        vector<long double> days1 = {22, 26, 33, 49, 70, 122};
        vector<long double> days2 = {7, 10, 15, 26, 43, 82};
        vector<long double> days;
        if (t == 1) days = days1;
        else days = days2;
        for (int i = 1; i <=W; i++) {
            cout << i << endl;
            cin >> days[i-1];
        }
        vector<vector<long double>> a = {
            {2, 1, 1, 1, 1, 1},
            {4, 2, 1, 1, 1, 1},
            {8, 2, 2, 1, 1, 1},
            {16, 4, 2, 2, 1, 1},
            {32, 4, 2, 2, 2, 1},
            {64, 8, 4, 2, 2, 2},
        };
        vector<long double> ans(6, 0);

        auto res = popup::linear_solve<long double>(a, days, ans);
        D("res: %d\n", res);
        for (auto r : ans) {
            cout << (int)round(r) << " ";
        }
        cout << endl;

        int oracle;
        cin >> oracle;
        if (oracle < 0) exit(0);
    }

    return 0;
}
