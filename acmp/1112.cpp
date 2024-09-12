/**
 * https://acmp.ru/asp/do/index.asp?main=task&id_course=1&id_section=1&id_topic=27&id_problem=155
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;

    while (n>0) {
        sum += n%10;
        n/=10;
    }

    cout << sum << endl;
}