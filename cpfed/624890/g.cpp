/**
 * https://vjudge.net/contest/624890#problem/G
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

double f(double x, int a, int b) {
    return x*x + a*x + b;
}

double ternary_search(double l, double r, int a, int b) {
    double eps = 1e-9;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double f1 = f(m1, a, b);
        double f2 = f(m2, a, b);
        
        if (f1 < f2) {
            r = m2;
        }
        else {
            l = m1;
        }
    }

    // return the midpoint of the final interval as the approximate minimum
    return (l+r)/2;
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int a, b;
    cin >> a >> b;

    double l = -1e6;
    double r = 1e6;

    printf("%.2f", ternary_search(l, r, a, b));
}