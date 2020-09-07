#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    while(1){
        int n, a0;
        cin >> n >> a0;
        double dp[n+1][a0+1];
        int i, j;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= a0; j++){
                if(i == 1) {dp[i][j] = 1.0/(j+1);continue;}
                double next = 1.0;
                for(int k = 1; k <= j; k++) next += dp[i-1][k];
                dp[i][j] = next / (j+1);
            }
        }
        cout << setprecision(5) << setiosflags(ios::fixed) <<  dp[n][a0] << endl;
    }
    return 0;
}