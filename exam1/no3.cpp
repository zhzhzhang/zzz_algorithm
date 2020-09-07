/**
 * 
 * 麻将胡牌
 * 
 * */
#include<iostream>
#include<vector>
using namespace std;

bool dfs(int a[], int mode){
    bool isok = true;
    if(mode == 0){
        for(int i = 1; i < 10; i++){
            if(a[i] > 2) {
                a[i] -= 3;
                isok = dfs(a, 0) || dfs(a, 1);
                a[i] += 3;
                return isok;
            }
            else if(a[i]) isok = false;
        }
        return isok;
    }
    else {
        for(int i = 1; i < 8; i++){
            if(a[i]&&a[i+1]&&a[i+2]){
                a[i]--;a[i+1]--;a[i+2]--;
                isok = dfs(a,0) || dfs(a,1);
                a[i]++;a[i+1]++;a[i+2]++;
                return isok;
            }
            else if(a[i]) isok = false;
        }
        if(a[8] || a[9]) return false;
        return isok;
    }
    
}
int main(){
    while(1){
    int a[10] = {0,0,0,0,0,0,0,0,0,0};
    int i = 13;
    int num;
    while(i--) {
        cin >> num;
        a[num] ++;
    }
    int j;
    vector<int> ans;
    for(i = 1; i <= 9; i++){
        if(a[i] == 4) continue;
        a[i] ++;
        bool isok = false;
        for(j = 1; j <= 9; j ++){
            if(a[j] < 2) continue;
            a[j] -= 2;
            isok = dfs(a, 0) || dfs(a, 1);
            a[j] += 2;
            if(isok) 
                break;
        }
        if(isok) 
            ans.push_back(i);
        a[i] --;
    }
    for(i = 0; i < ans.size(); i++){
        if(i == ans.size()-1) cout << ans[i] <<endl;
        else cout << ans[i] << " ";
    }
    if(ans.empty())
        cout << 0 <<endl;
}
    return 0;
}