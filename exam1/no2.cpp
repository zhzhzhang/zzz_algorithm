/**
 * 滑动窗口计算最大距离小于D的三点可能的位置
 * 
 **/
#include<iostream>
using namespace std;
int main(){
    while(1){
   int n,d;
    cin >> n >> d;
    int a[n];
    int i;
    for(i = 0; i < n; i++) cin >> a[i];
    int p1 = 0,p2 = 2;
    long long ans = 0;
    while(p2 < n && a[p2]-a[p1] <= d) p2++;
    if(p2-p1 > 2)
        ans += (p2-p1)*(p2-p1-1)*(p2-p1-2) / 6;
    for(;p2<n;p2++){
        if(p2-p1 < 2) continue;
        while(a[p2]-a[p1]>d) p1++;
        if(p2-p1 >= 2) ans += (long long)(p2-p1)*(p2-p1-1) / 2;
    }
    cout << ans <<endl;
}return 0;
}