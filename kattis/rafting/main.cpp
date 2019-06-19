#include <bits/stdc++.h>
#include "line_segment.hpp"
#include <limits>
using namespace std;
using namespace popup;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int tests;
    cin >> tests;
    cout << setprecision(16);
    cout << fixed;
    while(tests--) {
        size_t in_cnt, out_cnt;

        cin >> in_cnt;
        vector<Point<2, long double>> inner_segments;
        for(size_t i = 0; i < in_cnt; i++) {
            long double a, b;
            cin >> a >> b;
            inner_segments.push_back(Point<2, long double>({a, b}));
        }
        inner_segments.push_back(inner_segments[0]);

        cin >> out_cnt;
        vector<Point<2, long double>> outer_segments;
        for(size_t i = 0; i < out_cnt; i++) {
            long double a, b;
            cin >> a >> b;
            outer_segments.push_back(Point<2, long double>({a, b}));
        }
        outer_segments.push_back(outer_segments[0]);

        long double min_dist = numeric_limits<long double>::max();
        for (size_t i = 0; i < in_cnt; i++) {
            LineSegment<long double> in_line(inner_segments[i], inner_segments[i+1]);
            for (size_t j = 0; j < out_cnt; j++) {
                LineSegment<long double> out_line(outer_segments[j], outer_segments[j+1]);
                min_dist = min(min_dist, in_line.distance_to(out_line));
            }
        }

        min_dist /= 2;
        cout << min_dist << endl;
        // printf("%.8f\n", min_dist);
    }

    return 0;
}
