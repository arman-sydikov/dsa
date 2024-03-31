/**
 * https://vjudge.net/contest/619296#problem/J
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int acid;
    Cell *prev;
    pair<int, int> pos;
};

Cell* minCell(Cell &a, Cell &b) {
    if (a.acid < b.acid) {
        return &a;
    }
    return &b;
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n, m;
    cin >> n >> m;
    Cell dp[n+1][m+1];

    // init left cells
    for (int i=1; i<=n; i++) {
        dp[i][0].acid = INT_MAX;
    }
    // init top cells
    for (int j=1; j<=m; j++) {
        dp[0][j].acid = INT_MAX;
    }
    // init first cell
    dp[1][0].acid = 0;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int acid;
            cin >> acid;

            Cell* prevCell = minCell(dp[i-1][j], dp[i][j-1]);
            dp[i][j].acid = acid + prevCell->acid;
            dp[i][j].pos = make_pair(i, j);
            dp[i][j].prev = (i==1 && j==1) ? NULL : prevCell;
        }
    }

    // print minimal possible turtle's damage
    cout << dp[n][m].acid << endl;

    // build cells coordinates
    vector<pair<int, int>> coords;
    Cell* temp = &dp[n][m];
    while (temp != NULL) {
        coords.push_back(temp->pos);
        temp = temp->prev;
    }

    // print the cells coordinates
    for (int i = coords.size()-1; i >= 0; i--) {
        printf("%d %d\n", coords[i].first, coords[i].second);
    }
}