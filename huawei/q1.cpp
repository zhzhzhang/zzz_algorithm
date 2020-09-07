#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
int main(){
    string strin;
    cin >> strin;
    stringstream sstr(strin);
    map<string, int> mmp;
    string name;
    int num = 0;
    while(getline(sstr, name, ',')){
        if(name[0] > 'a') {
            cout << "error.0001" << endl;
            return 0;
        }
        if(mmp.count(name)) {
            mmp[name]++;
            num = max(mmp[name], num);
        }
        else mmp[name] = 0;
    }
    map<string, int>::iterator it;
    for(it = mmp.begin(); it != mmp.end(); it++){
        if(it->second == num) {
            cout << it->first << endl;
            break;
        }
    }
return 0;
}