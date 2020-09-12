#include<iostream>
#include<string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.size() * 2;
    int res = 0;
    for(int i = 1; i <= len; i ++) {
        int k = 1;
        while(i-k >= 0 && i+k <= len && (((i-k)%2 == 0) || str[(i-k)/2] == str[(i+k)/2])) {
            k++;
        }
        res += (k-1)/2;
    }
    cout << res << endl;
    return 0;
}