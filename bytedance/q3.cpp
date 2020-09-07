#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    while(1){
    int n,m;
    cin >> n >> m;
    int i, j;
    int a[n],b[m];
    for(i = 0; i < n; i++) cin >> a[i];
    for(i = 0; i < m; i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    j = n-1;
    long long ans = 0;
    for(i = m-1; i >= 0; i--){
        while(j >= 0 && a[j] > b[i]) j--;
        ans += b[i] - a[j];
    }
    cout << ans << endl;
}
    return 0;
}