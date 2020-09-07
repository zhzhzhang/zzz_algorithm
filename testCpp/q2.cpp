#include<iostream>
using namespace std;
int main(){
    int n,m,f;
    cin >> n >> m >> f;
    bool ill[n];
    for(int i = 0; i < n; i++) ill[i] = false;
    ill[f] = true;
    int p,num=0;
    bool has;
    for(int i = 0; i < m; i++){
        cin >> p;
        int a[p];
        has = false;
        for(int j = 0; j < p; j++){
            cin >> a[j];
            if(ill[a[j]]) has = true;
        }
        if(has) {
            for(int j = 0; j < p; j++)
                ill[a[j]] = true;
        }
    }
    for(int i = 0; i < n; i++)
    if(ill[i]) num ++;
    cout<<num<<endl;
    getchar();
    getchar();
    return 0;
}