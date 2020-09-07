#include<iostream>
#include<queue>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int q;
        queue<int> qe;
        cin >> q;
        string str;
        int num;
        while(q--){
            cin >> str;
            if(str == "PUSH"){
                cin >> num;
                qe.push(num);
                continue;
            }
            if(str == "POP"){
                if(qe.size() == 0) cout << -1 << endl;
                else qe.pop();
            }
            else if(str ==  "TOP"){
                if(qe.size() == 0) cout<<-1<<endl;
                else  cout << qe.front()<<endl;
            }
            else if(str == "SIZE") cout << qe.size() <<endl;
            else if(str == "CLEAR") while(!qe.empty()) qe.pop();
        }
    }
    return 0;
}