#include<iostream>
#include<vector>
using namespace std;
int main(){
while(1){
    int n,m;
    cin >> n >> m;
    int top[m];
    for(int i = 0; i < m; i++)
        top[i] = 0;
    int t;
    vector<vector<int> > num(m);
    bool used[n];
    for(int i = 0; i < n; i++){
        used[i] = false;
        for(int j = 0; j < m; j++){
            cin >> t;
            if(top[j] < t){
                top[j] = t;
                num[j].clear();
                num[j].push_back(i);
            }
            else if(top[j] == t) num[j].push_back(i);
        }
    }
    int res = 0; 
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < num[i].size(); j++){
            used[num[i][j]] = true;
        }
    for(int i = 0; i < n; i++)
        if(used[i]) res++;
    cout << res << endl;
    
}
return 0;
}