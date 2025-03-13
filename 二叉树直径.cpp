#include<iostream>
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
    static int record;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(record!=0){
            record=0;
        }
        getHeight(root);
        return record;

    }
    int getHeight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int lefthigh=getHeight(root->left);
        int righthigh=getHeight(root->right);
        if(lefthigh+righthigh>record){
            record=lefthigh+righthigh;
            cout<<"record"<<record<<endl;
        }
        return max(lefthigh,righthigh)+1;
    }
};
int Solution::record=0;