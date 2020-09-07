#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    while(1){
    int n,m;
    cin >> n;
    int h[n];
    int i;
    for(i = 0; i < n; i++) cin >> h[i];
    cin >> m;
    int w[m];
    for(i = 0; i < m; i++) cin >> w[i];
    sort(w,w+m,[](int& a,int& b){return a > b;});
    sort(h,h+n,[](int& a,int& b){return a > b;});
    int res = 0;
    i = 0; 
    int j = 0;
    while(i < n && j < m){
        if(h[i] <= w[j]) {
            res ++;
            i ++;
            j ++;
        }
        else i++;
    }
    cout << res <<endl;
    }
    return 0;
}