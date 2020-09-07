#include<iostream>
#include<stack>
using namespace std;

string change(string& s){
    string ans = "";
    stack<char> mystack;
    char t;
    for(int i = 0; i < s.size(); i++){
        if(s[i] <= 'z' && s[i] >= 'a') ans += s[i];
        else if(s[i] != ')'){
            if(mystack.empty() || s[i] == '(') mystack.push(s[i]);
            else {
                t = mystack.top();
                if(s[i] == '*' || s[i] == '/'){
                while(t == '*' || t == '/') {
                    ans+=t;
                    mystack.pop();
                    if(mystack.empty()) break;
                    t = mystack.top();
                }
                mystack.push(s[i]);
                }
                else{
                    while(t != '(') {
                    ans+=t;
                    mystack.pop();
                    if(mystack.empty()) break;
                    t = mystack.top();
                }
                mystack.push(s[i]);
                }
            }
        }
        else {
            while(mystack.top()!='('){
                ans += mystack.top();
                mystack.pop();
            }
            mystack.pop();
        }
    }
    while(!mystack.empty()){
        ans += mystack.top();
        mystack.pop();
    }
    return ans;
}
int main(){
    string str = "a+b*c+(d/(e-f))+g";
    cout << change(str) << endl;
    getchar();
    return 0;
}