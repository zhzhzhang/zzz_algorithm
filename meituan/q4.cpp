#include<iostream>
using namespace std;
int main(){
while(1){
    int n,k;
    cin >> n >> k;
    int a;
    int i;
    int left = 0, equl = 0, right = 0;
    for(i = 0; i < n; i++) {
        cin >> a;
        if(a == k) equl++;
        else if(a < k) left++;
        else right++;
    }
    if(left == right) cout << 0 << endl;
    else if(left < right){
        left += equl - 1;
        if(left >= right-1) cout << 0 << endl;
        else cout << right-left-1 << endl;
    }
    else{
        right += equl - 1;
        if(right >= left) cout << 0 << endl;
        else cout << left-right << endl;
    }
}
return 0;
}