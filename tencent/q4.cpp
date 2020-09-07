#include<iostream>
#include<cmath>
using namespace std;
long long mpow(int k){
    if(k == 1) return 2;
    return (long long)2*mpow(k-1);
}
int main(){
    int q;
    cin >> q;
    while(q--){
        long long x ;
        int k;
        cin >> x >> k;
        long long key = mpow(k);
        if(x > key-1){
            x/=2;
            while(x > key-1) 
                x /= 2;
            cout << x << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}