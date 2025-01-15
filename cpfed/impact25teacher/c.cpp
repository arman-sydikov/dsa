/**
 * https://esep.cpfed.kz/problem/413939
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long c[n];
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }
    
    long long buy = 0, remain = 0, stock = 0;
    for (int i=0; i<n; i++) {
        buy += c[i];
        stock++;
        bool temp = false;
        for (int j=i+1; j<n; j++) {
            if (c[j] > c[i]) {
                temp = true;
                break;
            }
        }
        if (!temp) {
            remain += stock*c[i] - buy;
            stock = 0;
            buy = 0;
        }
    }
    cout << remain << endl;
}