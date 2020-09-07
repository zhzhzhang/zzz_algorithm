#include<iostream>
#include<algorithm>
using namespace std;

void sort(int a[], int n) {
    int i, j;
    for(i = 1; i < n; i++){
        j = i-1;
        int t = a[i];
        while(j>=0 && a[j] > t) {a[j+1] = a[j]; j--;}
        a[j+1] = t;
    }
    return ;
}
 //shell排序
void sort2(int a[], int n) {
    for(int gap = n/2; gap > 0; gap/=2) {
        for(int i = gap; i < n; i++) {
            int t = a[i];
            int j = i-gap;
            while(j >= 0 && a[j] > t) {a[j+gap] = a[j]; j -= gap; }
            a[j+gap] = t;
        }
    }
}

int main(){
    while(1){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort2(a, n);
    for(auto i : a) cout << i << " " ;
    }
    return 0;
}

