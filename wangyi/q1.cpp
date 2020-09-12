#include<iostream>
#include<unordered_map>
using namespace std;
 struct child{
     int left;
     int right;
     child(int l = 0, int r = 0) : left(l), right(r) {}
 };

 int main() {
     int m, n;
     cin >> m >> n;
     int id1, id2;
     string str;
     unordered_map<int, child> tree;
     for(int i = 0; i < n; i++) {
         cin >> id1;
         cin >> str;
         cin >> id2;
         if(tree.find(id1) != tree.end()) {
             if(str == "left")
                tree[id1].left = id2;
             else {
                 tree[id1].right = id2;
             }
         }
         else {
             if(str == "left") {
                 child ch(id2, 0);
                 tree[id1] = ch;
             }
             else {
                 child ch(0, id2);
                 tree[id1] = ch;
             }
         }
     }
     int res = 0;
     for(auto it : tree) {
         if(tree.find(it.second.left) == tree.end() && tree.find(it.second.right) == tree.end()) res++;
     }
     cout << res << endl;
     return 0;
 }

