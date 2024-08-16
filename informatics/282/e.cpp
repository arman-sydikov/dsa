/**
 * https://informatics.msk.ru/mod/statements/view.php?id=282&chapterid=358#1
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, answer;
    cin >> n >> m;

    // наилучший результат предыдущих спортсменов
    int highest_res = INT_MIN;
    // наибольшая сумма результатов по всем попыткам
    int highest_sum = INT_MIN;
    
    for (int i=0; i<n; i++) {
        // сумма результатов по всем попыткам спортсмена
        int my_sum = 0;

        // наилучший результат текущего спортсмена
        int my_highest = INT_MIN;

        for (int j=0; j<m; j++) {
            int result;
            cin >> result;
            my_sum += result;

            if (result > my_highest) {
                my_highest = result;
            }
        }

        if (my_highest > highest_res) {
            // спортсмен с максимальным наилучшим броском
            highest_res = my_highest;
            highest_sum = my_sum;
            answer = i;
        } else if (my_highest == highest_res && my_sum > highest_sum) {
            // спортсмен с наилучшей суммой результатов по всем попыткам
            highest_sum = my_sum;
            answer = i;
        }
    }

    cout << answer << endl;
}