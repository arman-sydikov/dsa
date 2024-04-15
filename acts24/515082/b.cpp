/**
 * https://acts24.contest.codeforces.com/group/vBAsk1jzAW/contest/515082/problem/B
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n, m;
    cin >> n >> m;
    bool safe[n+1][n+1];
    memset(safe, true, sizeof(safe));
    while (m--) {
        int x, y;
        cin >> x >> y;
        // horizontal line
        for (int i=1; i<=n; i++) {
            safe[y][i] = false;
        }
        // vertical line
        for (int i=1; i<=n; i++) {
            safe[i][x] = false;
        }
        // diagonal lines
        int steps = 0;
        while (x-steps >= 1 || y-steps >= 1 || x+steps <= n || y+steps <= n) {
            if (x-steps >= 1 && y-steps >= 1) {
                safe[y-steps][x-steps] = false;
            }
            if (x-steps >= 1 && y+steps <= n) {
                safe[y+steps][x-steps] = false;
            }
            if (x+steps <= n && y-steps >= 1) {
                safe[y-steps][x+steps] = false;
            }
            if (x+steps <= n && y+steps <= n) {
                safe[y+steps][x+steps] = false;
            }
            steps++;
        }
    }

    int sum = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (safe[i][j]) {
                sum++;
            }
        }
    }
    
    // output
    cout << sum;
}