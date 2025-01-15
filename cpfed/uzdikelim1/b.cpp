/**
 * https://esep.cpfed.kz/problem/uzdikelim1b
 * @author Arman Sydikov
 * 
 * 2 4 5 1 5 4
 * 1 2 4 4 5 5
 * 5 5 4 4 2 1
 * 5 4 2 1
 * 2 2 1 1
 */
#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        m[a]++;
    }

    
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        cout << it->second << endl;
        n--;
    }

    while (n--) {
        cout << 0 << endl;
    }
}


// Например
2 4 5 1 5 4

{5, 2}
{4, 2}
{2, 1}
{1, 1}