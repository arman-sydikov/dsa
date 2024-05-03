/**
 * https://kazakh.contest.codeforces.com/group/XlHYPT9hCQ/contest/520517/problem/E
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

// Функция для определения типа скобки
int bracketType(char c) {
    if (c == '(' || c == ')') return 0;
    if (c == '[' || c == ']') return 1;
    if (c == '{' || c == '}') return 2;
    return -1;  // Недопустимый символ
}

// Функция для нахождения минимального количества удалений
// и восстановления правильной скобочной последовательности
string minRemovals(const string& s) {
    int n = s.length();
    if (n == 0) return "";  // Пустая строка
    
    // Двумерный массив для хранения минимального количества удалений
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Проходим по длине подстроки
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            // Если l и r - индексы начала и конца текущей подстроки
            // Найдем минимальное количество удалений для подстроки s[l..r]
            if ((s[l] == '(' && s[r] == ')') ||
                (s[l] == '[' && s[r] == ']') ||
                (s[l] == '{' && s[r] == '}')) {
                dp[l][r] = dp[l + 1][r - 1];
            } else {
                dp[l][r] = n;  // Инициализируем максимальным значением
                for (int k = l; k < r; ++k) {
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                }
            }
        }
    }
    
    // Функция для восстановления скобочной последовательности
    function<string(int, int)> restoreSequence = [&](int l, int r) -> string {
        if (l > r) return "";
        if (l == r) return string(1, s[l]);  // Одиночный символ
        if ((s[l] == '(' && s[r] == ')') ||
            (s[l] == '[' && s[r] == ']') ||
            (s[l] == '{' && s[r] == '}')) {
            return s[l] + restoreSequence(l + 1, r - 1) + s[r];
        }
        for (int k = l; k < r; ++k) {
            if (dp[l][r] == dp[l][k] + dp[k + 1][r]) {
                return restoreSequence(l, k) + restoreSequence(k + 1, r);
            }
        }
        return "";  // Недостижимый код
    };
    
    // Восстанавливаем результат для всей строки s
    return restoreSequence(0, n - 1);
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    
    string result = minRemovals(input);
    if (result.empty()) {
        cout << "-1";
    } else {
        cout << result;
    }
    
}
// https://qna.habr.com/q/934791
// {]((}][(}]))