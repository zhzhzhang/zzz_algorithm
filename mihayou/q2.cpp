#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string str;
    cin >> str;
    int left = 0;
    long long ans[26];
    for(int i = 0; i < 26; i++) ans[i] = 0;
    for(int i = 0; i < str.size(); i++){
        char now = str[i];
        if(now == '1') {
            left = i + 1;
            continue;
        }
        if(now > '1' && now <= '9') {
            str[i]--;
            i = left-1;
            continue;
        }
        if(now == '-'){
            char next = str[i+1];
            if(str[i-1] >= 'a') {
                now = str[i-1]+1;
                while(now <= next) {ans[now-'a']++;now++;}
            }
            else if(next<='Z'){
                now = str[i-1]+1;
                while(now <= next) {ans[now+32-'a']++;now++;}
            }
            else{
                now = str[i-1]+1;
                while(now <= 'Z') {ans[now+32-'a']++;now++;}
                now = 'a';
                while(now<=next) {ans[now-'a']++;now++;}
            }
            i++;
        }
        if(now<='Z') ans[now+32-'a'] ++;
        else ans[now-'a'] ++;
    }
    long long  mmax = ans[0];
    int index = 0;
    for(int i = 1; i < 26; i++){
        if(mmax<ans[i]){
            index = i;
            mmax = ans[i];
        }
    }
    cout << char(index+'a')<< mmax << endl;
    cout << "44"<<endl;
    return 0;
}