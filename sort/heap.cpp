#include<iostream>
#include<algorithm>
using namespace std;

void maxify(int a[], int size, int k) {
    int l = 2*k;
    int r = 2*k+1;
    int max = k;
    if(l <= size && a[l-1] > a[k-1]) max = l;
    if(r <= size && a[r-1] > a[max-1]) max = r;
    if(k != max) {
        swap(a[k-1], a[max-1]);
        maxify(a, size, max);
    }
}

void sort(int a[], int n) {
    for(int i = n/2; i > 0; i--) 
        maxify(a, n, i);
    for(int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);
        maxify(a, i, 1);
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
    sort(a, n);
    for(auto i : a) cout << i << " " ;
    }
    return 0;
}