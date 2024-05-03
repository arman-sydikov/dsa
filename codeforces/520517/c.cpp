/**
 * https://kazakh.contest.codeforces.com/group/XlHYPT9hCQ/contest/520517/problem/C
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    Point points[3];
    for (int i=0; i<3; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // center of triangle
    double x = (points[0].x + points[1].x + points[2].x) / 3;
    double y = (points[0].y + points[1].y + points[2].y) / 3;
    printf("%.4f %.4f\n", x, y);

    double shortest = DBL_MAX; 
    for (int i=0; i<3; i++) {
        double xd = max(x, points[i].x) - min(x, points[i].x);
        double yd = max(y, points[i].y) - min(y, points[i].y);
        shortest = min(shortest, sqrt(xd*xd + yd*yd));
    }
    printf("%.4f", shortest);
}