#include<iostream>
#include<algorithm>
using namespace std;

void sort(int a[], int n) {
    int i, j;
    for(i = 0; i < n-1; i ++) 
        for(j = 0; j < n - i -1; j ++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    return ;
}

int main(){
    while(1){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, n);
    for(auto i : a) cout << i << " " ;
    }
    return 0;
}
