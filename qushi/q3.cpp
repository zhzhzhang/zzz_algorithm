#include<iostream>
#include<vector>
using namespace std;
int main(){
    string str;
    vector<string> ans;
    cin >> str;
    int len = str.size();
    int i, maxlen = 0;
    for(i = 1; i < 2*len; i++){
        int cur = i%2 +1;
        while((i-cur)>=0 && (i+cur)<2*len){
            if(str[(i+cur)/2] == str[(i-cur)/2]) {
                cur += 2;
            }
            else break;
        }
        cur--;
        if(cur < 2) continue;
        if(cur>maxlen){
            maxlen = cur;
            ans.clear();
            ans.push_back(str.substr(i/2-cur/2, cur));
        }
        else if(cur == maxlen){
            ans.push_back(str.substr(i/2-cur/2, cur));
        }
    }
    if(maxlen)
    for(auto s : ans) cout << s << endl;
    else cout << "null" << endl;
    return 0;
}