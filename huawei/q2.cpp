#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    string name;
    string value;
    cin >> name;
    cin >> value;
    stringstream str(value);
    string flag;
    string addr;
    string mask;
    string val;
    for(int i = 0; i < value.size(); i++){
        getline(str, flag, '[');
        if(name == flag){
            getline(str, addr, '=');
            getline(str, addr, ',');
            getline(str, mask, '=');
            getline(str, mask, ',');
            getline(str, val, '=');
            getline(str, val, ']');
            cout << addr << " " << mask << " " << val << endl;
        }
        else {
            getline(str, flag, ']');
            str.get();
        }
    }
    return 0;
}