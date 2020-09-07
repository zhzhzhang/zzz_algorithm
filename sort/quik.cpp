#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[], int left, int right) {
    int key = a[left];
    while(left < right) {
        while(left < right && a[right] >= key) right--;
        if(left < right) a[left++] = a[right];
        while(left < right && a[left] <= key) left++;
        if(left < right) a[right--] = a[left];
    }
    a[left] = key;
    return left;
}

void sort(int a[], int left, int right) {
    if(left < right) {
        int p = partition(a, left, right);
        sort(a, left, p);
        sort(a, p+1, right);
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
    sort(a, 0, n-1);
    for(auto i : a) cout << i << " " ;
    }
    return 0;
}