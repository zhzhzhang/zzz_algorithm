#include<iostream>
using namespace std;
int main(){
while(1){
    int n;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++) num[i] = i+1;
    int k = 1;
    int ans;
    int left = n;
    int i = 0;
    while(left){
        int cur = k;
        while(cur || !num[i]){
            if(num[i] != 0)
            {
                cur--;
                i = (i+1)%n;
            }
            else i = (i+1)%n;
        }
        num[i] = 0;
        left--;
        ans = i+1;
        k++;
        i = (i+1) % n;
    }
    cout << ans << endl;
}
return 0;
}