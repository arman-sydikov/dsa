/**
 * Задача E. Треугольник на оси
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Высоты треугольника
    int a = INT_MAX;
    int b = INT_MIN;
    int h = 0;
    int k = 0;

    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;

        if (y == 0) {
            k++;
            a = min(a, x);
            b = max(a, x);
        } else {
            h = max(h, abs(y));
        }
    }

    double area = 0;
    if (k >= 2) {
        area = 0.5 * (b - a) * h;
    }

    printf("%.9lf", area);
}