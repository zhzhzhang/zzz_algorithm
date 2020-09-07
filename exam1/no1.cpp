#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int len;
    bool mut;
    while(n--){
        string str;
        cin >> str;
        if(str == "") continue;
        int k = 1;
        mut = false;
        len = str.size();
        char res[len+1];
        res[0] = str[0];
        for(int i = 1; i < len; i++){
            if(str[i] == str[i-1] && !mut){
                mut = true;
                res[k++] = str[i];
            }
            else if(str[i]==str[i-1])
                continue;
            else if(mut){
                res[k++] = str[i];
                while(i+1 < len && str[i+1] == str[i]) i++;
                mut = false;
            }
            else res[k++] = str[i];
        }
        res[k] = '\0';
        cout << res <<endl;
    }
    return 0;
}