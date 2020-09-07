#include<iostream>
#include<cmath>
using namespace std;
int main(){
    while(1){
    int n,m;
    cin >> n >> m;
    int dp1[m],dp2[m]; // 前缀中，余数为j的个数
    long long res = 0;
    int i, j;
    long long  A[n];
    for(i = 0; i < n; i++){
        cin >> A[i];
    }     
    for(i = 0; i < m ;i++) dp1[i] = 0;
    dp1[A[0]%m] = 1; 
    res += dp1[0]; 
    int pre;
    int num;
    for(i = 1; i < n; i++){
        pre = A[i] % m;
        for(j = 0; j < m; j++)
             dp2[j] = dp1[(m+j-pre)%m];
        dp2[pre] += 1;
        for(j = 0; j<m ; j++)
             dp1[j] = dp2[j];
        res+=dp2[0];     
            
    }
    cout<<res<<endl;
    }
    return 0;
}