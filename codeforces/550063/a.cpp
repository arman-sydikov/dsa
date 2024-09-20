/**
 * https://codeforces.com/group/u8pLzn9xS6/contest/550063/problem/A
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    unordered_map<string, int> m;
    for (int i=0; i<n-1; i++) {
        string temp = s.substr(i, 2);
        m[temp]++;
    }

    string max_bigram;
    int max_count = 0;
    
    for (const auto& entry : m) {
        if (entry.second > max_count) {
            max_bigram = entry.first;
            max_count = entry.second;
        }
    }

    cout << max_bigram << endl;
}