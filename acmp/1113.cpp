/**
 * https://acmp.ru/asp/do/index.asp?main=task&id_course=1&id_section=1&id_topic=27&id_problem=156
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if ((a%b==0) || (b%a==0)) {
        cout << 1 << endl;
    } else {
        cout << 666 << endl;
    }
}