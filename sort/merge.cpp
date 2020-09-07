#include<iostream>
#include<algorithm>
using namespace std;

void merge(int a[], int left, int mid, int right) {
    int cp[right-left+1];
    for(int i = left; i <= right; i++) {
        cp[i-left] = a[i];
    }
    int l = left, r = mid+1;
    for(int i = left; i <= right; i++) {
        if(l > mid ) {
            a[i] = cp[r - left];
            r++;
        }
        else if(r > right) {
            a[i] = cp[l - left];
            l++;
        }
        else if(cp[l-left] > cp[r-left]) {
            a[i] = cp[r-left];
            r++;
        }
        else {
            a[i] = cp[l-left];
            l++;
        }
    }
}

void sort(int a[], int left, int right ) {
    if(left < right) { 
        int mid = (left+right) / 2;
        sort(a, mid+1, right);
        sort(a, left, mid);
        merge(a, left, mid, right);
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
    sort(a, 0, n-1);
    for(auto i : a) cout << i << " " ;
    }
    return 0;
}