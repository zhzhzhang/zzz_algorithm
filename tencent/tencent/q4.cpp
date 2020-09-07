#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    cin >> m;
    int ffinal = a[n-1];
    bool dp[n][m];
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m; j++) {
            if(j == 0) {
                dp[i][j] = false;
                continue;
            }
            if(i == 0) {
                if(j == a[i])
                    dp[i][j] = true;
                else 
                    dp[i][j] = false;
                continue;
            }
            if(j < a[i]) {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            if(dp[i-1][j-a[i]]) 
                dp[i][j] = true;
            else 
                dp[i][j] = false;
        }
    }
    for(int j = m-1; j >= 0; j--)
        for(int i = 0; i < n-1; i++)
            if(dp[i][j]) {
                cout << j + ffinal << endl;
                return 0 ;
            }
    return 0;
}