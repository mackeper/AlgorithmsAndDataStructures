#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include "rat_part_lin_eq_solver.hpp"
#include "rational.hpp"

#define trav(x, a) for(auto &x : a)

using namespace std;

void extractEquation(
        string &str, 
        size_t idx, 
        vector<vector<popup::Rational<int64_t>>> &A, 
        vector<popup::Rational<int64_t>> &b
        ) {
    stringstream ss(str);
    string term;
    popup::Rational<int64_t> afterequal(1,1);
    popup::Rational<int64_t> negative(1,1);
    while(ss >> term) {
        int symbol = 3;
        popup::Rational<int64_t> value(true);
        trav(c, term) {
            if(c == 'x') {
                symbol = 0;
            } else if (c == 'y') {
                symbol = 1;
            } else if (48 <= c && c <= 57) {
                if(symbol > 2)
                    symbol = 2;
                if(value.nan()) {
                    value = popup::Rational<int64_t>(c-48,1);
                } else {
                    value.numenator() *= 10;
                    value.numenator() += c-48;
                }
            } else if(c == '-') {
                negative.numenator() = negative.numenator() < 0 ? 1 : -1;
            } else if(c == '=') {
                afterequal.numenator() = -1;
            }
        }

        if(symbol == 2) {
            b[idx] += negative*afterequal*value*popup::Rational<int64_t>(-1,1);
            negative.numenator() = 1;
        } else if(symbol < 2) {
            if(value.nan())
                value = popup::Rational<int64_t>(1,1);
            A[idx][symbol] += negative*afterequal*value;
            negative.numenator() = 1;
        }
    }

}

int main() {
    int tests;
    scanf("%d", &tests);
    getchar(); // next line
    while(tests-- > 0) {
        string line1;
        string line2;
        getline(cin, line1);
        getline(cin, line2);
        getchar(); // next line
        //cout << line1 << endl;
        //cout << line2 << endl;

        vector<vector<popup::Rational<int64_t>>> 
            A(2, vector<popup::Rational<int64_t>>(2,popup::Rational<int64_t>(0, 1)));
        vector<popup::Rational<int64_t>> b(2, popup::Rational<int64_t>(0,1));
        vector<popup::Rational<int64_t>> ans(2, popup::Rational<int64_t>(0,1));

        extractEquation(line1, 0, A, b);
        extractEquation(line2, 1, A, b);

        if(0) {
            trav(outer, A) {
                trav(inner, outer) {
                    cout << inner.str() << " ";
                }
                cout << endl;
            }

            trav(i, b) {
                cout << i.str() << " "; 
            }
            cout << endl;
        }
        
        int res = popup::linear_solve(A, b, ans);
        if(res == 0) {
            cout << "don't know\n";
            cout << "don't know\n";
        } else {
            for(auto &v : ans) {
                if(v.nan()) {
                    cout << "don't know\n";
                } else {
                    if(v.denominator() == 1)
                        printf("%li\n", v.numenator());
                    else 
                        printf("%li/%li\n", v.numenator(), v.denominator());
                }
            }
        }
        

        cout << "\n";
    }


    return 0;
}
