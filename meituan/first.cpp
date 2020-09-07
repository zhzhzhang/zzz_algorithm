#include<iostream>
#include<set>
using namespace std;

int main() {
    while(1){
    int n, p, q;
    cin >> n >> p >> q;
    set<int> want;
    int num;
    int allWantNum = 0;
    for(int i = 0; i < p; i++) {
        cin >> num;
        want.insert(num);
    }
    for(int i = 0; i < q; i++) {
        cin >> num; 
        if(want.find(num) != want.end()) {
            allWantNum++;
        }
    }
    cout << p-allWantNum << " " << q-allWantNum << " " << allWantNum << endl;
    }
    return 0;
}