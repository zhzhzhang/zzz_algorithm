#include<iostream>
#include<vector>
using namespace std;

int main() {
    while(1) {
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int i1=0, i2=0;
    vector<int> res;
    while(i1 < n && i2 < m) {
        if(a[i1] == b[i2]) {
            res.push_back(a[i1]);
            i1++;
            i2++;
        }
        else if(a[i1] < b[i2]) i2++;
        else i1++;
    }
    for(int i = 0; i < res.size()-1; i++) {
        cout << res[i] << " ";
    }
    cout << res[res.size()-1] << endl;
    }
    return 0;
}