/**
 * https://kazakh.contest.codeforces.com/group/XlHYPT9hCQ/contest/520517/problem/E
 * https://qna.habr.com/q/934791
 * @author Arman Sydikov
 * 
 *     (   (   )   [   {   }   ] 
 *   | 1 | 2 | 3 | 4 | 5 | 6 | 7 
 * --+---+---+---+---+---+---+---
 * 1 | 1                      
 * 2 | 2   1                  
 * 3 | 1   0   1              
 * 4 | 2   1   2   1          
 * 5 | 3   2   3   2   1      
 * 6 | 2   1   2   1   0   1   
 * 7 | 1   0   1   0   1   2   1
 */
#include <bits/stdc++.h>
using namespace std;
bool debug = false;

string minRemovals(string& s) {
    int n = s.size();
    set<int> m[n][n];

    if (debug) {
        cout << ". ";
        for (int i=0; i<n; i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    if (debug) {
        cout << "  ";
        for (int i=0; i<n; i++) {
            cout << i << " ";
        }
        cout << endl;
    }

    for (int i=0; i<n; i++) {
        for (int j=i; j>=0; j--) {
            if (i == j) {
                m[i][j].insert(i);
                continue;
            }
            
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                m[i][j].insert(m[i-1][j].begin(), m[i-1][j].end());
                m[i][j].insert(i);
                continue;
            }

            // m[i][j] = min(m[i-1][j] + 1, m[i][j+1] + 1);
            if (m[i-1][j].size() < m[i][j+1].size()) {
                m[i][j].insert(m[i-1][j].begin(), m[i-1][j].end());
                m[i][j].insert(i);
            } else {
                m[i][j].insert(m[i][j+1].begin(), m[i][j+1].end());
                m[i][j].insert(j);
            }
            
            if ((s[j] == '(' && s[i] == ')') || (s[j] == '[' && s[i] == ']') || (s[j] == '{' && s[i] == '}')) {
                // m[i][j] = min({m[i-1][j+1], m[i-1][j] + 1, m[i][j+1] + 1});
                if (m[i][j].size() > m[i-1][j+1].size()) {
                    m[i][j].clear();
                    m[i][j].insert(m[i-1][j+1].begin(), m[i-1][j+1].end());
                }
                continue;
            }

            if (s[j] == '(' || s[j] == '[' || s[j] == '{') {
                for (int z=j; z<i; z++) {
                    // m[i][j] = min({m[i][j], m[z][j] + m[i][z+1]});
                    if (m[i][j].size() > m[z][j].size() + m[i][z+1].size()) {
                        m[i][j].clear();
                        m[i][j].insert(m[z][j].begin(), m[z][j].end());
                        m[i][j].insert(m[i][z+1].begin(), m[i][z+1].end());
                    }
                }
            }
        }
    }

    // debug
    if (debug) {
        for (int i=0; i<n; i++) {
            cout << i << " ";
            for (int j=0; j<=i; j++) {
                cout << m[i][j].size() << " ";
            }
            cout << endl;
        }
    }

    // for (int cc : m[10][0]) {
    //     cout << cc << endl;
    // }
    string ans;
    for (int i=0; i<n; i++) {
        if (!m[n-1][0].count(i)) {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main() {
    // fast input
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input;
    cin >> input;
    
    string result = minRemovals(input);
    if (result.empty()) {
        cout << "-1";
    } else {
        cout << result;
    }
}