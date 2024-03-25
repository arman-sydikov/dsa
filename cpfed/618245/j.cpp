/**
 * https://vjudge.net/contest/618245#problem/N
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

// O(log b)
ll powerMod(ll a, ll b, ll c) {
    ll result = 1;
 
    // Сначала находим остаток от деления a на c
    a = a % c;
  
    // if (a == 0) return 0;
 
    while (b > 0) {
        // Если b - нечетное число, умножаем результат на a и находим остаток по модулю c
        if (b % 2 == 1) {
            result = (result * a) % c;
        }
 
        // Уменьшаем степень b вдвое и находим остаток от деления a^2 на c
        b = b/2 ;
        a = (a * a) % c; 
    } 
    return result;
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    ll a, b, c;
    cin >> a >> b >> c;
    
    cout << powerMod(a, b, c);
}