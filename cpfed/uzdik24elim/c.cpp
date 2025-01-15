/**
 * https://esep.cpfed.kz/problem/uzdik24elimc
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Читаем количество элементов массива и количество запросов
    int n, q; 
    cin >> n >> q;

    // hashmap для хранения индексов
    // key — это элемент из массива
    // value — вектор индексов, где встречается этот элемент
    unordered_map<int, vector<int>> m; 
    
    for (int i = 0; i < n; i++) {
        // Читаем очередной элемент массива
        int a;
        cin >> a;

        // Сохраняем индекс элемента в вектор значений hashmap
        // (i + 1, так как индексация начинается с 1)
        m[a].push_back(i + 1); 
    }

    // Цикл для обработки всех запросов (q раз)
    while (q--) {
        // Читаем запрос
        int x, k;
        cin >> x >> k; 

        // Проверяем, существует ли ключ `x` в hashmap
        if (m.count(x)) { 
            if (m[x].size() < k) { 
                // Если у числа `x` меньше вхождений, чем `k`, выводим -1
                cout << -1 << endl;
            } else {
                // Иначе выводим индекс `k`-го вхождения числа `x`
                cout << m[x][k - 1] << endl;
            }
        } else {
            // Если числа `x` вообще нет в массиве, выводим -1
            cout << -1 << endl;
        }
    }
}
