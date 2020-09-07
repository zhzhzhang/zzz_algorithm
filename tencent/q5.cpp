#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void change(int a[], int b[], int k){
    int t = a[k];
    a[k] = b[k+1];
    b[k+1] = t;
    t = b[k];
    b[k] = a[k+1];
    a[k+1] = t;
    return;
}
void dfs(int a[], int b[], int& ans, int k, int& n, int num){
    if(k == n-1){
        if(a[k] >= a[k-1]) ans = ans == -1 ? num : min(ans,num);
        return;
    }
    if(k == 0){
        dfs(a,b,ans,k+1,n,0);
        change(a,b,0);
        dfs(a,b,ans,k+1,n,num+1);
        change(a,b,0);
    }
    else {
        if(a[k-1]<=a[k]){
            dfs(a,b,ans,k+1,n,num);
            if(a[k-1]<=b[k+1]){
                change(a,b,k);
                dfs(a,b,ans,k+1,n,num+1);
                change(a,b,k);
            }
        }
        else if(a[k-1]<=b[k+1]){
            change(a,b,k);
            dfs(a,b,ans,k+1,n,num+1);
            change(a,b,k);
        }
        else return;
    }
}
int main(){
    int n;
    cin >> n;
    int i;
    int a[n],b[n];
    for(i = 0; i < n; i++) cin >> a[i];
    for(i = 0; i < n; i++) cin >> b[i];
    int ans = -1;
    dfs(a,b,ans,0,n,0);
    cout << ans << endl;
    return 0;
}