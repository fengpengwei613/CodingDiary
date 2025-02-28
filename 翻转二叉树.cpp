#include<iostream>
#include<queue>
using namespace std;
/*
题目给定一个二叉树，要求翻转左右子节点。
题目很简答，直接层次遍历(BFS)，用queue，调换left和right即可。
*/

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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return root;
        }
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* tmp;
        while(!que.empty()){
            
            tmp=que.front()->left;
            que.front()->left=que.front()->right;
            que.front()->right=tmp;
            if(que.front()->left!=nullptr){
                que.push(que.front()->left);
            }
            if(que.front()->right!=nullptr){
                que.push(que.front()->right);
            }
            que.pop();
        }
        return root;
    }
};