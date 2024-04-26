/**
 * https://cpfedcoach24.contest.codeforces.com/group/Y0bboME4W4/contest/506992/problem/E
 * @author Arman Sydikov
 */
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// Dynamic Programming - bottom up aproach
void bottomUp(ll &sum, int a[], int n) {
    ll dp = 0;
    for (int i=1; i<n; i++) {
        int distance = a[i] - a[i-1];
        dp += i * distance;
        sum += dp;
    }
}

// Dynamic Programming - top down aproach
ll topDown(ll &sum, int a[], int i) {
    if (i==0) {
        return 0;
    }

    int distance = a[i] - a[i-1];
    ll dp = topDown(sum, a, i-1) + i * distance;
    sum += dp;
    return dp;
}

int main() {
    // input n
    int n;
    cin >> n;

    // input x,y
    int x[n];
    int y[n];
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x, x+n);
    sort(y, y+n);

    ll sumX = 0;
    ll sumY = 0;
    // bottomUp(sumX, x, n);
    // bottomUp(sumY, y, n);
    topDown(sumX, x, n-1);
    topDown(sumY, y, n-1);
    ll answer = sumX + sumY;

    // print answer
    cout << answer;
}