/**
 * https://informatics.msk.ru/mod/statements/view.php?id=268&chapterid=1414#1
 * @author Arman Sydikov
 * 
 * 4
 * 1 2 -1 3 1 -2 -1 4 1 2
 */
#include <bits/stdc++.h>
using namespace std;

void rec(string action, int n) {
    if (n < 1) {
        return;
    }

    if (action == "fill") {
        rec("fill", n-1);
        rec("del", n-2);
        printf("%d ", n);
        rec("fill", n-2);
    } else {
        rec("del", n-2);
        printf("-%d ", n);
        rec("fill", n-2);
        rec("del", n-1);
    }
}

void write(int n) {
    cout << n << ' ';
}

void clear(int n);
void setCell(int n);

void clear(int n) {  
    if (n > 0) {     
        setCell(n - 1);  
        write(-n);   
        clear(n - 1);
    }
}

void setCell(int n) {    
    if (n > 0) {     
        setCell(n - 1);  
        write(n);    
        clear(n - 1);
    }
}

void fill(int n) {  
    if (n > 0) {    
        setCell(n - 1); 
        write(n);   
        fill(n - 2);
    }
}

int main() {
    int n;
    cin >> n;

    // rec("fill", n);
    fill(n);
}