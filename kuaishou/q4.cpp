#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int> >& num, int x, int y,  bool& flag){
    if(num[x][y] != 1)  return ;
    int m = num.size(), n = num[0].size();
    flag = flag && !(x==0 || y==0 || x==m-1 || y==n-1);
    num[x][y] = -1;
    if(x-1 >= 0 && num[x-1][y] == 1) dfs(num, x-1, y, flag);
    if(x+1 < m && num[x+1][y] == 1) dfs(num,x+1,y, flag);
    if(y-1 >= 0 && num[x][y-1] == 1) dfs(num, x, y-1, flag);
    if(y+1 < n && num[x][y+1] == 1) dfs(num, x, y+1, flag);   
    return ;
}
int main(){
    int x,y;
    cin >> x >> y;
    vector<vector<int> > num(x,vector<int>(y,0));
    int i,j;
    for(i = 0; i < x; i++)
        for(j = 0; j < y; j++) 
            cin >> num[i][j];
    int ans = 0;
    bool flag;
    for(i = 0; i < x; i++)
        for(j = 0; j < y; j++){
            if(num[i][j] == 1)
            {
                flag = true;
                dfs(num, i, j, flag);
                ans += flag;
            }
        }
    cout << ans << endl;
    return 0;

}