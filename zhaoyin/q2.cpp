#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool hasOne(set<int>& received, vector<int>& ids) {
    for(auto id : ids) {
        if(received.find(id) != received.end()) return true;
    }
    return false;
}

int main() {
    while(1){
    int n, m, x;
    cin >> n >> m;
    vector<vector<int> > a;
    bool received[m];
    set<int> receivedId;
    for(int i = 0; i < m; i++) {
        received[i] = false;
        cin >> x;
        vector<int> ai;
        int id;
        for(int j = 0; j < x; j++) {
            cin >> id;
            if(id == 0) {
                received[i] = true;
            }
            ai.push_back(id);
        }
        a.push_back(ai);
        if(received[i]) {
            for(int k = 0; k < x; k++)
                receivedId.insert(ai[k]);
        }
    }
    if(receivedId.empty()) {
        cout << 0 << endl;
        return 0;
    } 
    int preSize = 0;
    while(preSize != receivedId.size()){
        preSize = receivedId.size();
        for(int i = 0; i < m; i++) {
            if(received[i]) continue;
            if(hasOne(receivedId, a[i])) {
                for(int j = 0; j < a[i].size(); j++) {
                    receivedId.insert(a[i][j]);
                }
            }
        }
    }
    cout << receivedId.size() << endl;
}
    return 0;
}