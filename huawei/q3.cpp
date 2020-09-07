#include<iostream>
#include<vector>
using namespace std;

int getmax(int n, int k, int mmax[], bool used[], bool& huan, int w[], vector<vector<int> >& a){
    if(mmax[k]>0) return mmax[k];
    if(huan) return 0;
    if(used[k]) {cout << "R" << endl; huan = true;return 0;}
    int mm = 0;
    used[k] = true;
    for(int i = 0; i < a[k].size(); i ++){
        if(mmax[a[k][i]]) mm = max(mm,mmax[a[k][i]]);
        else
        mm = max(mm, getmax(n,a[k][i],mmax,used,huan,w,a));
    }
    mmax[k] = w[k] + mm;
    return mmax[k];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> >  a(n);
    int w[n];
    int t[n];
    bool huan = false;
    int mmax[n];
    
    for(int i = 0; i < n; i++){
        cin >> t[i];
        mmax[i] = 0;
    }
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(cin.get() == '\n') {
            cout << "NA" << endl;
            return 0;
        }
        cin >> w[i];
        for(int j = 0; j < t[i]; j++)
        {
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        bool used[n];
        huan = false;
        for(int t = 0; t < n; t++) used[t] = false;
        if(mmax[i]) continue;
        getmax(n,i,mmax,used,huan,w,a);
        res = max(res, mmax[i]);
    }
    if(huan) return 0;
    cout << res << endl;
    // for(int i=0; i < n; i++){
    //     cout << w[i] << " ";
    //     for(int j = 0; j < t[i]; j++)
    //     cout << a[i][j] << " ";
    //     cout << endl;
    // }
    getchar();
    getchar();
    return 0;
       
}