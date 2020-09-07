#include<iostream>
#include<string>
using namespace std;

int main(){
    int t, n, i;
    string ass;
    cin >> t;
    while(t--){
        cin >> n;
        int k = 0,a[n],b;
        bool ok = true;
        bool used = false;
        for(i = 0; i < n; i++) cin >> a[i];
        for(i = 0; i < n; i++){
            cin >> b;
            int ab = b - a[i];
            if(ab == k) continue;
            if(ab == 0 && !used) { used = true; k = 0; continue;}
            if(k == 0) k = ab;
            else ok = false;
        } 
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
