#include <iostream>
using namespace std;

int main() {
    while(1) {
    int m, l;
    cin >> m >> l;
    int h[l];
    int minh = INT_MAX;
    int highest;
    for(int i = 0; i < l; i++) {
        cin >> h[i];
        if(h[i] < minh) {
            minh = h[i];
            highest = i;
        }
    }
    highest = 0;
    int res = 0;
    int leftH = h[0];
    for(int i = 1; i < highest; i++) {
        if(h[i] > leftH) {
            res += h[i] - leftH;
        }
        else {
            leftH = h[i];
        }
    }
    int rightH = h[l-1];
    for(int i = l-1; i >= highest; i--) {
        if(h[i] > rightH) {
            res += h[i] - rightH;
        }
        else {
            rightH = h[i];
        }
    }
    cout << res*m << endl; 
    }
    return 0;
}