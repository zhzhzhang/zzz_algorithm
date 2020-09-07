#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int i,j;
    vector<int> num;
    map<int,int> mp;
    for(i = 0; i < n; i++){
        cin >> j;
        num.push_back(j);
        mp[j] = i;
    }
    int ans = 0,b;
    for(i = 0; i < n; i+=2){
        if(num[i]-num[i+1] == 1 || num[i]-num[i+1] == -1) continue;
        if(num[i] % 2) 
             b = num[i] - 1;
        else  b = num[i]+1;
            int t = mp[b];
            mp[num[i+1]] = t;
            swap(num[i+1],num[t]);
            mp[b] = i+1;
            ans++;
    }
    cout << ans << endl;
    return 0;
}