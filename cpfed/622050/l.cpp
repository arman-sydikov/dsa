/**
 * https://vjudge.net/contest/622050#problem/L
 * https://www.youtube.com/watch?v=zxxrR2oa0-M
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const long long MOD = 1000000007;

// Функция для вычисления количества способов расставить учеников
int count_ways(int m, int n, vector<ll>& factorial) {
    int boys = m - n;
    int girls = n;

    ll boys_perm = factorial[boys];
    ll girls_perm = factorial[boys+1] / factorial[boys-girls+1];

    // Return the total number of ways
    return (boys_perm * girls_perm) % MOD;
}

int main() {
    // Создаем вектор для хранения факториалов
    vector<ll> factorial(1000000+1);
    factorial[0] = 1;

    // Вычисляем факториалы
    for (int i = 1; i <= 1000000; ++i) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    
    // input
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        cout << count_ways(m, n, factorial) << endl;
    }
}
