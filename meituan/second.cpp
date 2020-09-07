#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
    while(1) {
    string str;
    cin >> str;
    int len = str.size();
    int num = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] < 91) num ++;
    }
    cout << abs(num-len/2) << endl;}
    return 0;
}