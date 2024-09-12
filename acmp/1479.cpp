/**
 * https://acmp.ru/asp/do/index.asp?main=task&id_course=1&id_section=1&id_topic=27&id_problem=1436
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, m;
    cin >> a >> b;

    m = a%b;
    if (m < 0) {
        m += abs(b);
    }

    cout << m << endl;
}