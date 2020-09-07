#ifndef SERVER_INFO
#define SERVER_INFO
#include<string>
#include<vector>
using namespace std;
class Server{
    string ip;
    vector<int> port;
    string dn;
    double stability;
    int multser;
    class Info{
    public:
        Info(){}
    } info;
public:
    Server(string IP,vector<int> Port,string DN,double Stab,int Mul):ip(IP),port(Port),dn(DN),stability(Stab),multser(Mul){}
    string getip(){return ip;}
    vector<int>& getport(){return port;}
    string getdn(){return dn;}
    double getstab(){return stability;}
    int getmult(){return multser;}
    Info getinfo(){return info;}

};
#endif