#include<iostream>
using namespace std;
class x{
    int i;
public:
    x(int ii = 0);
    static void fff(){cout<<"fdsf"<<endl;return;}
    void modify() {i++;};
};
x::x(int ii) { i = ii; }

x f1(){
    return x();
}
const x f2(){
    return x();
}
int f3(){
    static int tt = 45;
    return 3;
}
int& f5(int& a){
    return a;
}
int* f6(int& a){
    return &a;
}
void f4(int& xx){
    return;
}
int main(){
    f1() = x(2);  //对于自定义类型，返回值可以作为左值使用，但还是右值，无法给非const引用
    f1().modify();
    // f4(f1()); //f1()返回值是右值
    //f3() = 4; //对于内建类型，返回值是右值，编译出错。
    int a = 3;
    int b = 4;
    
    f4(f5(a)); //虽然是右值，但本身就是&，所以赋值给形参没问题。
    f5(a) = b; //&可以作为左值使用
    *(&b) = 9;
    *f6(a) = b;
    cout<<&f5(a)<<endl;
    cout<<a<<endl;
    getchar();
    return 0;
}