#include<iostream>
#include<stack>
#include<set>
using namespace std;

int main() {
    while(1) {
    int m;
    cin >> m;
    set<int> hasUsed;
    stack<int> stk;
    int a;
    for(int i = 0; i < m ; i++) {
        cin >> a;
        stk.push(a);
    }
    while(!stk.empty()) {
        if(hasUsed.find(stk.top()) == hasUsed.end()){
            cout << stk.top() << endl;
            hasUsed.insert(stk.top());
        }
        	
        stk.pop();    }
    }
    return 0;
}