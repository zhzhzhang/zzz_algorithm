#include<iostream>
#include<algorithm>
using namespace std;
int main(){
while(1){
    int n,k;
    cin >> n >> k;
    int i;
    int a[n];
    for(i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int t = k%n;
    int first = t ? k/n : k/n - 1;
    int second = t ? t-1 : n-1;
    cout << "(" << a[first] << "," << a[second] << ")" << endl;
}
return 0;
}