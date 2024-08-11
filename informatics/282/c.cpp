/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=356#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, answer, highest = INT_MIN;
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=0; j<m; j++) {
            int result;
            cin >> result;
            sum += result;
        }
        if (sum > highest) {
            highest = sum;
            answer = i;
        }
    }

    cout << highest << endl;
    cout << answer << endl;
}