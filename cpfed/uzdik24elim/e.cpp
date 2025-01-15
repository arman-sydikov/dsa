/**
 * https://esep.cpfed.kz/problem/uzdik24elime
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>
using namespace std;

string s;

long long rec(long long prefix, long long suffix, size_t idx) {
    if (idx == s.size()) {
        return prefix + suffix;
    }

    long long curr = s[idx]-'0';
    return rec(prefix, suffix*10+curr, idx+1) + rec(prefix+suffix, curr, idx+1);
}

int main() {
    cin >> s;

    long long suffix = s[0]-'0';
    cout << rec(0, suffix, 1) << endl;
}
