/**
 * https://esep.cpfed.kz/problem/uzdikelim2d
 * @author Arman Sydikov
 * 
 * 4
 * 1 4
 * 4 3
 * 4 10
 * 8 3
 */
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> floors;
unordered_map<int, bool> visited;
queue<int> q;

int main() {
    int n, answer = 1;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        floors[a].push_back(b);
        floors[b].push_back(a);
        visited[a] = false;
        visited[b] = false;
    }

    // Бірінші қабаттан бастаймыз
    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
        int current_floor = q.front();
        q.pop();
        answer = max(answer, current_floor);

        for (int floor : floors[current_floor]) {
            if (!visited[floor]) {
                visited[floor] = true;
                q.push(floor);
            }
        }
    }

    cout << answer << endl;
}

