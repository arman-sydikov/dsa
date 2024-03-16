/**
 * https://vjudge.net/contest/616148#problem/A
 * @author Arman Sydikov
 */
#include <iostream>

using namespace std;

int modify(int x) {
    if (x % 2 == 0) {
        return x / 2;
    }
    return x + 1;
}

int main() {
    int n, answer = 0;
    cin >> n;

    while (n > 1) {
        n = modify(n);
        answer++;
    }

    cout << answer;
}