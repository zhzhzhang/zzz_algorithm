#include "serverInfo.h"
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<memory.h>
#include<cstdlib>
#include<iomanip>
using namespace std;

struct node{
    vector<int> port;
    vector<string> active;
    string dn;
};

double getstab(vector<string>& active){
    int num = active.size();
    int act = 0;
    for(auto str : active){
        for(char c : str){
            if(c == '1') act++;
        }
    }
    return (double)act / (num*7.0);
}

void initinfo(vector<Server*>& servers){
    map<string, node*> infos;
    ifstream inserver("D:/ips.txt");
    string ip;
    string port;
    string dn;
    string active;
    while(inserver >> ip){
        inserver >> port;
        inserver >> dn;
        inserver >> active;
        if(infos.find(ip) != infos.end()){
            infos[ip]->port.push_back(atoi(port.c_str()));
            infos[ip]->active.push_back(active);
        }
        else{
            node* tn = new node();
            tn->port.push_back(atoi(port.c_str()));
            tn->active.push_back(active);
            tn->dn = dn;
            infos[ip] = tn;
        }
    }
    double stab;
    for(auto info : infos){
        node* t = info.second;
        stab = getstab(t->active);
        servers.push_back(new Server(info.first,t->port,t->dn,stab,t->port.size()));
        delete t;
    }
}

int main(){    
    vector<Server*> servers;
    initinfo(servers);
    cout << servers.size() << endl;
    int a[10];
    double s[10];
    map<double,int> stabinfo;
    memset(a,0,sizeof(a));
    memset(s,0,sizeof(s));
    ofstream outfile("D:/servers_ip.txt");
    for(auto server : servers){
        outfile << server->getip() << endl;
        a[server->getmult()]++;
        s[server->getmult()]+=server->getstab();
        if(stabinfo.find(server->getstab()) == stabinfo.end()) stabinfo[server->getstab()] = 1;
        else stabinfo[server->getstab()]++;
        delete server;
    }
    for(int i=0;i<10;i++) cout << i << ":" << a[i] << ":" << setprecision(2)<< setiosflags(ios::fixed)<<s[i]/a[i]<<endl;
    for(auto stab : stabinfo){
        cout << setprecision(2)<< setiosflags(ios::fixed) <<stab.first << ":" << stab.second << endl;
    }
    getchar();
    return 0;
}