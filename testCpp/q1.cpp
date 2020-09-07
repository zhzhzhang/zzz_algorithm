#include<iostream>
using namespace std;
int main(){
    while(1){
    int n,m,s;
    cin >> n >> m >> s;
    int a[n];
    for(int i = 0; i < n; i++) a[i] = 0;
    a[s-1] = 1;
    int c1, c2, i;
    int num = n-1;
    for(i = 0; i < m; i++){
        cin >> c1 >> c2;
        if(c1 == 0 && c2 == s) {
            cout<<i+1<<endl;
            break;
        }
        if( (c1 == 0 || c1 == s) && a[c2-1] == 0){
            num --;
            a[c2-1] = 1;
        } 
        else if(c2 == s && a[c1-1] == 0){
            num --;
            a[c1-1] = 1;
        } 
        if(num == 0) {
            cout << i+1<<endl;
            break;
        }
    }
    if(i == m) cout<< 0<<endl;
    }
    return 0;
}