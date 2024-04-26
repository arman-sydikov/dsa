/**
 * https://vjudge.net/contest/616148#problem/E
 * @author Arman Sydikov
 */
#include <bits/stdc++.h>

using namespace std;

struct Box {
    int value, weight;
    double ratio;
};

bool cmp(Box first, Box second) {
    return first.ratio > second.ratio;
}

int main() {
    // fast input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // input
    int n, w;
    cin >> n >> w;
    Box boxes[n];
    for (int i = 0; i < n; i++) {
        cin >> boxes[i].value >> boxes[i].weight;
        boxes[i].ratio = (double)boxes[i].value / boxes[i].weight;
    }
    
    sort(boxes, boxes+n, cmp) ;
    
    double maxValue = 0;
    for (int i = 0; i < n; i++) {
        if (boxes[i].weight <= w) {
            maxValue += boxes [i].value;
            w -= boxes[i].weight;
        } else {
            maxValue += (double) w * boxes[i].value / boxes[i].weight;
            break;
        }
    }

    printf("%.3lf", maxValue);
}