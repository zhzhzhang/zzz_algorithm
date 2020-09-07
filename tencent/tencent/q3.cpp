#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string str;
    unordered_map<string, int> str2Int;
    map<int, vector<string> > int2Str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str2Int.find(str) != str2Int.end()) {
            str2Int[str] ++;
        }
        else {
            str2Int[str] = 1;
        }
    }
    for(auto it = str2Int.begin(); it != str2Int.end(); it++) {
        if(int2Str.find(it->second) != int2Str.end()) {
            int2Str[it->second].push_back(it->first);
        }
        else {
            vector<string> tmp(1, it->first);
            int2Str[it->second] = tmp;
        }
    }
    int num = k;
    vector<string> strs;
    for(auto it = --int2Str.end(); ; it--) {
        sort(it->second.begin(), it->second.end());
        strs = it->second;
        for(auto s : strs) {
            if(num == 0) break;
            cout << s << " " << it->first << endl;
            num --;
        }
        if(num == 0) break;
        if(it == int2Str.begin()) break;
    }
    num = k;
    for(auto it = int2Str.begin(); it != int2Str.end(); it++) {
        sort(it->second.begin(), it->second.end());
        strs = it->second;
        for(auto s : strs) {
            if(num == 0) break;
            cout << s << " " << it->first << endl;
            num --;
        }
        if(num == 0) break;
    }
    return 0;
}