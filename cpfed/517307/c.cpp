/**
 * https://esep.contest.codeforces.com/group/eSjC23OibW/contest/517307/problem/C
 * @author Arman Sydikov
 */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // input
    long long a, b;
    cin >> a >> b;

    // Вычисляем гипотенузу как целое число
    long long c = sqrt(a*a + b*b);

    // output
    cout << c;
}