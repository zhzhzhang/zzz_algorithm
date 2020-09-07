#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
while(1){
    int a,b,m,x;
    unordered_map<int, int> flag;
    cin >> a >> b >> m >> x;
    x = (a*x+b)%m;
    cout << x << " ";
    int i = 0;
    flag[x] = i++;
    x = (a*x+b)%m;
    while(flag.count(x) == 0){
        flag[x] = i++;
        cout << x << " ";
        x = (a*x+b)%m;
    } 
    cout << x << endl;
    cout << i-flag[x] << endl;

}
return 0;
}