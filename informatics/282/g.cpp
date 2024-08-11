/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=360#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, answer;
    cin >> n >> m;

    // наилучший результат спортсменов
    int highest_res = INT_MIN;
    
    int a[n];
    for (int i=0; i<n; i++) {
        // наилучший результат текущего спортсмена
        int my_highest = INT_MIN;

        for (int j=0; j<m; j++) {
            int result;
            cin >> result;

            if (result > my_highest) {
                my_highest = result;
            }
        }
        a[i] = my_highest;

        if (my_highest > highest_res) {
            // спортсмен с максимальным наилучшим броском
            highest_res = my_highest;
            answer = 1;
        } else if (my_highest == highest_res) {
            // ещё один спортсмен с максимальным наилучшим броском
            answer++;
        }
    }

    cout << answer << endl;
    
    for (int i=0; i<n; i++) {
        if (a[i] == highest_res) {
            cout << i << endl;
        }
    }
}