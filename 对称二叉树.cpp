#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        return judge(root->left,root->right);
        
    }
    bool judge(TreeNode * left,TreeNode *right){
        if(left==nullptr&&right==nullptr){
            return true;
        }else if(left==nullptr^right==nullptr){
            return false;
        }
        if(left->val==right->val){
            return judge(left->left,right->right)&&judge(left->right,right->left);
        }else{
            return false;
        }
    }
};