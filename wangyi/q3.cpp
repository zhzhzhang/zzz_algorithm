#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.size();
    int i, j;
    int res = 0;
    for(i = 0; i < len; i++) {
        set<char> has;
        int right = i;
        for(j = i; j < len; j++) {
            char c = str[j];
            if(c >= 'a' && c <= 'c' || (c >= 'x' && c <= 'z')){
                if(has.find(c) == has.end()) has.insert(c);
                else has.erase(c);
            }
            if(has.empty()) right = j;
        }
        res = max(res, right-i+1);
    }
    cout << res << endl;
    return 0;
}