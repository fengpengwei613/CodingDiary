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
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return res;
        }
        middle(root);
        return res;
    }
    void middle(TreeNode * root){
        
        if(root->left!=nullptr){
            middle(root->left);
        }
        res.push_back(root->val);
        if(root->right!=nullptr){
            middle(root->right);
        }
        
    }
};