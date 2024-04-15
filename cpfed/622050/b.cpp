/**
 * https://vjudge.net/contest/622050#problem/B
 * @author Arman Sydikov
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // open files
    ifstream input("inverse.in");
    ofstream output("inverse.out");

    // input
    int n;
    input >> n;
    int p[n+1];
    int q[n+1];
    for (int i=1; i<=n; i++) {
        input >> p[i];
        q[p[i]] = i;
    }

    for (int i=1; i<=n; i++) {
        output << q[i] << " ";
    }

    // close files
    input.close();
    output.close();
}