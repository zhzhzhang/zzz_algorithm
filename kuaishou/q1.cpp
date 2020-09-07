#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<string, set<string> > res;
    string url;
    string dn;
    string req;
    int pts;
    while(n--){
        cin >> url;
        pts = url.find("/",7);
        if(pts == url.npos) continue;
        dn = url.substr(0,pts);
        req = url.substr(pts);
        if(res.find(dn) != res.end()) res[dn].insert(req);
        else {
            set<string> reqs;
            reqs.insert(req);
            res[dn] = reqs;
        }
    }
    map<set<string>, string > ans;
    int num = 0;
    for(auto dom : res){
        if(ans.find(dom.second) != ans.end()) {ans[dom.second] += " "+dom.first;if(ans[dom.second].find(" ") == ans[dom.second].npos) num++;}
        else
            ans[dom.second] = dom.first;
    }
    cout << num << endl;
    for(auto r : ans){
        if(r.second.find(" ") != r.second.npos) {
            cout << r.second << endl;
        }
    }
    return 0;
}