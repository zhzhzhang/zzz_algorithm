#include<iostream>

using namespace std;

int main(){
while(1){
    char a[5][5] = {{'a','b','c','d','e'},{'f','g','h','i','j'}};
    char (*p)[5] = a;
    char b[4] = {'a','g','h','k'};
    char *t = b;
    cout << *(t+2) << endl;
    cout << *(*(p+1) +2 )<< endl;  //输出h
}
    return 0;
}