#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<unsigned int, unsigned int> > range;
    unsigned int left,right;
    unsigned int k,i;
    for(i = 0; i < n; i++){
        cin >> left >> right;
        range.push_back(pair<unsigned int, unsigned int>(left,right-1));
    }
    sort(range.begin(),range.end(),[](pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b){return a.first <= b.first;});
    unsigned int ans = 1;
    k = 0;
    for(i = 1; i < n ;i++){
        if(range[k].second >= range[i].first){
            ans = max(ans,i-k+1);
        }
        else{
            k++;
            i--;
        }
    }
    cout << ans << endl;
    getchar();
    getchar();
    return 0;
}