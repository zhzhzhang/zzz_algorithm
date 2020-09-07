#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n],i;
        for(i = 0; i < n; i++) cin >> a[i];
        long long right[n],left[n];
        left[0] = -1;
        right[n-1] = n;
        int k;
        for(i = 1; i < n; i++){
            k = i-1;
            while(k > 0  && a[k] <= a[i]) k = left[k] - 1;
            if(k == -1) left[i] = 0;
            else if(a[k] <= a[i]) left[i] = k; 
            else left[i] = k+1;
        }
        for(i = n-2; i >= 0; i--){
            k = i+1;
            while(k < n-1 && a[k] <= a[i]) k = right[k] + 1;
            if(k == n) right[i] = n-1;
            else if(a[k] <= a[i]) right[i] = k; 
            else right[i] = k-1;
        }
        cout << right[0] << " ";
        for(i = 1; i < n-1; i++) cout << (i - left[i]) + (right[i] - i) << " ";
        cout << n - 1 - left[n-1] << endl;
    }    
    return 0;
}