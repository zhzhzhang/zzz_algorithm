#include<iostream>
#include<vector>
using namespace std;

int main(){
    while(1){
    int n,i;
    cin >> n;
    int ll[n];
    for(i = 0; i < n; i++) cin >> ll[i];
    int ans = 0;
    int t = 1;
    for(i = n-2; i >= 0; i--){
        if(ll[i] > ll[i+1]) {
            if(ll[i]/2 >= ll[i+1]){
                ans ++;
                ll[i] -= ll[i+1];
                i++;
            }
            else{
                ans ++;
                ll[i] /= 2;
            }
        }

    }
    cout << ans << endl;
}
return 0;

}