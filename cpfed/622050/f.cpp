/**
 * https://vjudge.net/contest/622050#problem/F
 * https://en.wikipedia.org/wiki/Combinatorial_number_system#Finding_the_k-combination_for_a_given_number
 * @author Arman Sydikov
 */
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Функция для вычисления биномиального коэффициента C(n, k)
int binomial_coefficient(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - k + i) / i;
    }
    return (int)(res + 0.01);
}

void backtracking(ofstream& output, int a[], int n, int k, int level, int start, int p) {
    // leaf node
    if (level > k) {
        for (int i=1; i<=k; i++) {
            output << a[i] << " ";
        }
        output << endl;
        return;
    }

    for (int i=start; i<=n; i++) {
        int b = binomial_coefficient(n - i, k - level);
        if (b <= p) {
            p -= b;
            continue;
        }
        
        a[level] = i;
        backtracking(output, a, n, k, level+1, i+1, p);
        break;
    }
}

int main() {
    // open files
    ifstream input("comb.in");
    ofstream output("comb.out");

    int n, k, p;
    input >> n >> k >> p;

    int a[n+1];
    backtracking(output, a, n, k, 1, 1, p);

    // close files
    input.close();
    output.close();
}
