#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<string> strs;
    string str;
    int i;
    while(cin >> str){
        strs.push_back(str);
        if(cin.get() == '\n'){
            sort(strs.begin(),strs.end());
            for(i = 0; i < strs.size() - 1; i++)
                cout<<strs[i]<<" ";
            cout<<strs[i]<<endl;
            strs.clear();
        }
    }
    return 0;
}