#include<iostream>
#include<algorithm>
using namespace std;

void sort(int a[], int n) {
    int i, j, k;
    for(i = 0; i < n-1; i++) {
        k = i;
        for(j = i; j < n; j++){
            if(a[j] < a[k]) k = j;
        }
        swap(a[k],a[i]);
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

