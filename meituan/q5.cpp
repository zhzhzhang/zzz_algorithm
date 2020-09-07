#include<iostream>
#include<string>
using namespace std;
int main(){
while(1){
    string s,t;
    cin >> s;
    cin >> t;
    int slen = s.size();
    int tlen = t.size();
    int dp[slen+1][tlen+1];
    int i,j,k;
    long long res = 0;
    for(i = 0; i <= slen; i++) dp[i][0] = 0;
    for(i = 0; i <= tlen; i++) dp[0][i] = 0;
    for(i = 1; i <= slen; i++)
        for(j = 1; j <= tlen; j++){
            dp[i][j] = dp[i][j-1];
            if(s[i-1] == t[j-1]){
                dp[i][j] += (dp[i-1][j-1] + 1);
            }   
        }
    long long mm = 1000000007;
    for(i = 1; i <= slen; i++)
        if(res >= mm) res -= mm; 
        res += dp[i][tlen];
    //cout << res << endl;
    cout << mm << endl;
 
}
return 0;
}