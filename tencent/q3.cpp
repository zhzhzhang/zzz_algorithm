#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st1;
    stack<int> st2;
    int t;
    cin >> t;
    string cmd;
    int num;
    while(t--){
        cin >> cmd;
        if(cmd == "add") {
            cin >> num;
            st1.push(num);
        }
        else if(cmd == "poll"){
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        else if(cmd == "peek"){
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            cout << st2.top() << endl;
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
    }
    return 0;
}