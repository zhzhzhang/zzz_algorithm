#include<iostream>
#include<cmath>
using namespace std;


int fun(string& num, int n, int m){
    int dp[n];
    int k,i,j;
    for(i = 0; i < n; i++){
        dp[i] = 0;
        for(j = 0; j <= i; j++){
            k = atoi(num.substr(j,i-j+1).c_str());
            if(k % m == 0) {
                if(j == 0) dp[i] ++;
                else dp[i] += dp[j-1];
            }
        }
    }
    return dp[n-1];
}

int main(){
    int t,n,m;
    cin >> t;
    int i,j;
    string num;
    for(i = 0; i < t; i++){
        cin >> n >> m;
        cin >> num;
        cout << fun(num, n, m) << endl;
    }
    return 0;
    
}