/**
 * https://vjudge.net/contest/622050#problem/D
 * @author Arman Sydikov
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void backtracking(ofstream& output, int a[], int n, int k, int level, int start) {
    // leaf node
    if (level > k) {
        for (int i=1; i<=k; i++) {
            output << a[i] << " ";
        }
        output << endl;
        return;
    }

    for (int i=start; i<=n; i++) {
        a[level] = i;
        backtracking(output, a, n, k, level+1, i+1);
    }
}

int main() {
    // open files
    ifstream input("choose.in");
    ofstream output("choose.out");

    // input
    int n, k;
    input >> n >> k;
    int a[k+1];
    backtracking(output, a, n, k, 1, 1);

    // close files
    input.close();
    output.close();
}