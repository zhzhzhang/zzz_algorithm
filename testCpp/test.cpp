#include<iostream>
#include<cstring>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;

void myfun(char a[], char* b, char* c){
    set<char> bset;
    a[0] = 'm';
    b[0] = '1';
    int m = strlen(b);
    int n = strlen(a);
    for(int i = 0 ; i < m; i++)
        bset.insert(b[i]);
    int k = 0;
    for(int i = 0; i < n; i++){
        if( bset.find(a[i]) == bset.end()){
            c[k++] = a[i];
        }
            
    }
    return;
}

class ccc {
public:
    int a;
    int b;
    int c;
    int q;
   // string ss; //加上这一句，就只能用delete[]，因为string有析构函数。
    ccc() {};
    ~ccc(){cout<<"析构"<<a<<endl;};
};
int w = 3;
const int e = 8; // 全局的常量，不能通过取地址进行修改。编译段错误
const int ee = w; //全局的只读变量，可以通过指针修改。

int main(int argc, char** argv){
    int o = 6;
    cout<<(-3)%5<<endl;
    const int ppp = o;
    const int p = 4; //局部的常量，可以指针取地址修改，但是输出p时扔取符号表未修改的数
    //const int& as = ee;
    //cout<<&o<<" ."<<&ppp<<" . "<<&p<<" . "<<&as<<endl;
      int* pp = const_cast<int*>(&ee);
    *pp = 2;
    cout << *pp << " ,"  << " ," << ee << endl;
    cout << "-----------------------" <<endl;
     //"-----------------------"   
    istringstream sins("sdkf glksd sgklgs");
    cout << sins.str();
     string sss;
    while(sins >> sss)
    cout<<sss<<endl;
    cout << "-----------------------" <<endl;
    //"--------------------------------"
    ccc* ob = new ccc[5];
    int* pt = new int;
    delete[] pt;//可以
    for(int i = 0; i<5; i++) ob[i].a=i*10;
    ob[7].a = 555;//越界，但是不会被检测到，因为ob[5]的位置才有检测gap 。
    //ob[5].a = 322;//越界，delete时检查gap发现越界会异常。
    //cout<<ob[5].a<<endl; 
    delete []ob;//可以。只有带析构函数的对象数组，必须用delete[]释放。
    cout<<"-------------------------"<<endl;
    //"------------------------------"
    int i = 0,t = 4;
    string strs[t];
    while(t--){
        cin >> strs[i++];
    }
    cout<<strs<<":"<<strs+1<<":"<<strs+2<<endl;
    sort(strs,strs+4);
    for(auto s : strs)
    cout<<s<<endl;
    getchar();
    getchar();
}