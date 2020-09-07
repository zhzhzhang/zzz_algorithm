#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
double getdes(int a, int b, int c, int d){
    double x = (a-b)*(a-b);
    double y = (c-d)*(c-d);
    return sqrt(x+y);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<pair<int, int> > A;
        vector<pair<int, int> > B;
        cin >> n;
        if(n == 0) continue;
        int i,x,y;
        for(i = 0; i < n; i++) {
            cin >> x >> y;
            A.push_back({x,y});
        }
        for(i = 0; i < n; i++) {
            cin >> x >> y;
            B.push_back({x,y});
        }
        double ans = getdes(A[0].first,B[0].first,A[0].second,B[0].second);
        // sort(A.begin(),A.end(),[](pair<int,int>& a,pair<int,int>& b){
        //     return a.first < b.first;
        // });
        // sort(B.begin(),B.end(),[](pair<int,int>& a,pair<int,int>& b){
        //     return a.first < b.first;
        // });
        for(auto a : A)
            for(auto b : B){
                double des = getdes(a.first,b.first,a.second,b.second);
                ans = min(ans,des);
            }
        cout << setprecision(3) << std::fixed << ans << endl;
    }
    return 0;
}