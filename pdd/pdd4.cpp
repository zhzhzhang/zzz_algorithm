#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int res;
vector<vector<vector<bool> > >* rem;
unordered_map<char, int> keyint ;
void dfs(vector<vector<char> >& lost, vector<vector<int> >& flag, int key, int x, int y, int step){
    int M = lost.size();
    int N = lost[0].size();
    if( x < 0 || x >= M || y < 0 || y >= N || lost[x][y] == '0' || (*rem)[key][x][y]) return ;
    if(lost[x][y] == '0'+3) {
        res = min(res, step);
        return;
    }
    if(lost[x][y] >= 'a' && lost[x][y] <= 'z') key += keyint[lost[x][y]];
    else if(lost[x][y] >= 'A' && lost[x][y] <= 'Z' && (keyint[lost[x][y]+32] & key) == 0) return ;
    (*rem)[key][x][y] = true;
    dfs(lost, flag,  key, x-1, y, step+1);
    dfs(lost, flag,  key, x+1, y, step+1);
    dfs(lost, flag, key, x, y-1, step+1);
    dfs(lost, flag, key, x, y+1, step+1);
    (*rem)[key][x][y] = false;
}
int main(){
    while(1){
    int M,N;
    res = INT_MAX;
    cin>>M>>N;
    if(M == 0 || N == 0) return 0;
    vector<vector<char> > lost(M, vector<char>(N));
    vector<vector<int> > flag(M, vector<int>(N,-1));
    int x, y;
    int nk = 0;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++){
            cin >> lost[i][j];
            if(lost[i][j] >= 'a' && lost[i][j] <= 'z' && keyint.count(lost[i][j]) == 0) {
                keyint[lost[i][j]] = 1 << nk;
                nk++;
            }
            if(lost[i][j] == ('0'+2) ) {
                x = i;y = j;
                flag[x][y] = 0;
            }
        }
    rem = new vector<vector<vector<bool> > >(2^nk, vector<vector<bool> >(M, vector<bool>(N, false)));
    dfs(lost, flag, 0, x-1, y, 1);
    dfs(lost, flag,0, x+1, y, 1);
    dfs(lost, flag,0, x, y-1, 1);
    dfs(lost, flag,0,x, y+1, 1);
    cout << res << endl;
    }
    return 0;
}