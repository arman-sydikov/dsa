/**
 * https://acmp.ru/asp/do/index.asp?main=task&id_course=1&id_section=1&id_topic=27&id_problem=157
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, t;
    cin >> v >> t;

    int d = 1 + (v * t) % 109;

    if (d <= 0) {
        d += 109;
    }

    cout << d << endl;
}