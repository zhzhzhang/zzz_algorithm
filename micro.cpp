#include<iostream>
#include<unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    /* data */
};

unordered_map<int, pair<int,int> > mmap;
int ans = 0;
void s_num(TreeNode* root, int num, int dep){
{
    if(root == NULL) return;
    if(mmap.find(num) != mmap.end()) mmap[num] = {root->val,dep};
    else if(dep < mmap[num].second) mmap[num] = {root->val,dep};
    s_num(root->left, num-1, dep+1);
    s_num(root->right, num+1, dep+1);
}




// int s_num(TreeNode* root){
//     int ans = 0;
//     queue<TreeNode*> tree;
//     set<int> used;
//     queue<int> num;
//     if(root==NULL) return ans;
//     tree.push(root);
//     num.push(0);
//     int tnum;
//     while(!tree.empty()){
//         root = tree.front();
//         tnum = num.front();
//         tree.pop();
//         num.pop();
//         if(used.find(tnum) == used.end()) ans+=root->val;
//         if(root->left) {
//             tree.push(root->left);
//             num.push(tnum-1);
//             used.insert(tnum-1);
//         }
//         if(root->right) {
//             tree.push(root->right);
//             num.push(tnum+1);
//             used.insert(tnum+1);
//         }
//     }
//     return ans;
// }


int main(){

}