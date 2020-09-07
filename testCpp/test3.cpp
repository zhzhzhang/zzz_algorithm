#include<iostream>
#include<cmath>
using namespace std;
int main(){
    while(1){
    int n,k,i,j;
    cin >> n >> k;
    int mmp[10] = {0,0,0,0,0,0,0,0,0,0};
    char a[n];
    for(i = 0; i < n; i++){
        cin >> a[i];
        mmp[a[i]-'0']++;
    }
    int key[10],num;
    
    int change[10][10];
    for(i = 0; i < 10; i++)
        for(j = 0; j<10; j++) 
            change[i][j] = 0;
    for(i = 0; i < 10; i++){
        num = mmp[i];
        if(num >= k) {
            cout << 0 << endl;
            cout<< a <<endl;
            return 0;
        }
        j = 1;
        key[i] = 0;
        while(num < k){
            if(i+j>=0 && i+j < 10){
                num += mmp[i+j];
                key[i] += (abs(j)*mmp[i+j]);
                change[i][i+j] = mmp[i+j];
            }
            j = j < 0 ? -j+1 : -j;
        }
        j = j < 0 ? -j : -j+1;
     
            key[i] -= (num-k)*abs(j);
            change[i][i+j] -= (num-k);
    }
    int mk = 0;
    for(i = 0 ; i < 10; i++){
        if(key[i] < key[mk]) mk = i;
    }
    cout<<key[mk]<<endl;

    for(i = 0; i < n; i++){
        if(a[i]-'0' <= mk) continue;
        if(change[mk][a[i]-'0']) {
            change[mk][a[i]-'0'] --;
            a[i] = mk+'0';
        }
    }
     for(i = n-1; i >= 0; i--){
         if(change[mk][a[i]-'0']) {   
                change[mk][a[i]-'0'] --;
                a[i] = mk+'0';
         }
     }
    cout << a<<endl;
}
    return 0;
    
}