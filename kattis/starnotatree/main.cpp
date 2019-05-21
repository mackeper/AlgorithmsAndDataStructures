#include <bits/stdc++.h>
#include "point.hpp"

using namespace std;
using namespace popup;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin, x.end()
#define sx(x) (int)(x).size()
typedef __int128 ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

long long sgn(long double x) {
     return (0 < x) - (x < 0);
}

long double dist(vector<Point2<long double>>& points, Point2<long double>& point) {
    long double s = 0;
    for (auto p : points) {
        s += p.distance_to(point);
    }
    return s;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout << setprecision(15);
    cout << fixed;
    int num_points;
    cin >> num_points;
    vector<Point2<long double>> points;
    points.reserve(num_points);

    for(int i = 0; i < num_points; i++) {
        double x, y;
        cin >> x >> y;
        points.emplace_back(Point2<long double>({x,y}));
    }

    Point2<long double> point({0,0});
    long double current_val = dist(points, point);
    long double move = 5000;
    const long double change = 0.95;
    while (move > 1e-20) {
        Point2<long double> cx({point[0] + 1.0*move, point[1]});
        Point2<long double> cy({point[0], point[1] + 1.0*move});
        auto cx_val = dist(points, cx);
        auto cy_val = dist(points, cy);

        point = Point2<long double>({
            point[0]+sgn(current_val-cx_val)*move,
            point[1]+sgn(current_val-cy_val)*move
        });
        current_val = dist(points, point);
        move *= change;
    }
    cout << (double)(current_val) << "\n";
}
