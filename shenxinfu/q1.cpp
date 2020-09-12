#include<iostream>
#include<vector>
using namespace std;

int res = 0;
int x,y;
int x1, x2, y1, y2;
vector<vector<bool> > room;
int eatNum = 0;
void dfs(int j, int i) {
    room[i][j] = true;
    eatNum ++;
    if(j == x2 && i == y2) {
        if(eatNum == x*y) res++;
        eatNum --;
        room[i][j] = false;
        return;
    }
    if(i+1 < y && !room[i+1][j]) {
        dfs(j, i+1);
    }
    if(i-1 >= 0 && !room[i-1][j]) {
        dfs(j, i-1);
    }
    if(j-1 >= 0 && !room[i][j-1]) {
        dfs(j-1, i);
    }
    if(j+1 < x && !room[i][j+1]) {
        dfs(j+1, i);
    }
    room[i][j] = false;
    eatNum--;
    return ;
}

int main() {
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    room.clear();
    for(int i = 0; i < y; i++) {
        room.push_back(vector<bool> (x, false));
    }
    dfs(x1, y1);
    cout << res << endl;
    return 0;
}