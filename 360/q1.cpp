#include<iostream>
#include<deque>
using namespace std;
int main(){
        int n, m;
        cin >> n >> m;
        int i;
        int win = 0;
        int res = 0;
        deque<int> fight;
        int t;
        for(i=0;i<n;i++){
            cin >> t;
            fight.push_back(t);
        }
        int a,b;
        while(win < m){
            a = fight.front();
            fight.pop_front();
            b = fight.front();
            fight.pop_front();
            if(a == n) {
                res += m-1;
                break;
            } 
            if(a < b){
                win = 1;
                res ++;
                fight.push_front(b);
                fight.push_back(a);
            }
            else{
                win ++;
                res++;
                fight.push_back(b);
                fight.push_front(a);
            }
        }
        cout << res << endl;
    return 0;
}