#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string num1,num2;
    stringstream res;
    cin >> num1 >> num2;
    int len1 = num1.size();
    int len2 = num2.size();
    int i,j;
    int a[len1+len2-1] ;
    for(i = 0; i < len1+len2-1; i++) a[i] = 0;
    for(i = 0; i < len1; i++)
        for(j = 0; j < len2; j++){
            a[i+j] += (num1[i]-'0') * (num2[j]-'0');
        }
    for(i = len1+len2-2; i > 0; i--){
        a[i-1] += a[i] / 10;
        a[i] %= 10;
    }
    for(i = 0; i < len1+len2-1; i++)
        res << a[i];
    cout << res.str() << endl;
        return 0;

}