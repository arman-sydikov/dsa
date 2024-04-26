/**
 * https://acts24.contest.codeforces.com/group/vBAsk1jzAW/contest/515082/problem/E
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int rec(vector<int> floor[], bool visited[], int s, int step, map<int, vector<int>> &m) {
    visited[s] = true;
    if (step>0) {
        m[step].push_back(s);
    }

    int big = step;
    for (int i : floor[s]) {
        if (!visited[i]) {
            big = max(big, rec(floor, visited, i, step+1, m));
        }
    }
    return big;
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    int n, s;
    cin >> n >> s;
    vector<int> floor[n+1];
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int temp;
            cin >> temp;
            floor[i].push_back(temp);
        }
    }
    
    // output
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    map<int, vector<int>> m;
    int maxSteps = rec(floor, visited, s, 0, m);
    cout << maxSteps << endl;
    sort(m[maxSteps].begin(), m[maxSteps].end());
    for (int i : m[maxSteps]) {
        cout << i << " ";
    }
}