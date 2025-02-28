#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
题目要求给出二叉树的任意两个节点，找到这两个节点的最近公共节点。
一种思路是利用dfs寻找两个点的路径，然后根据路径找到最接近的公共节点。传统的dfs寻找最短路径的方法，不过多介绍。
另外一种思路是递归思路。

*/
//dfs求路径题解
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> pRoot,qRoot;
        dfs(root,p,pRoot);
        dfs(root,q,qRoot);
        TreeNode* res=root;
        for(int i=0;i<pRoot.size()&&i<qRoot.size();i++)
        {
            if (pRoot[i]==qRoot[i])
            {
                res=pRoot[i];
            }
            else
            {
                break;
            }
        }
        return res;
        
    }
    bool dfs(TreeNode* root,TreeNode* trg,std::vector<TreeNode*> &path)
    {
        if(root==NULL)
        {
            return false;
        }
        path.push_back(root);
        if(root==trg)
        {
            return true;
        }
        if(dfs(root->left,trg,path)||dfs(root->right,trg,path))
        {
            return true;
        }
        else
        {
            path.pop_back();
            return false;
        }
        
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    }
    
};










//如果是二叉搜索树可以这样做(刚开始没看清题，尴尬)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p==root||q==root)
        {
            return root;
        }
        else if(root->val>p->val^root->val>q->val)
        {
            return root;
        }
        else if(root->val<p->val&&root->val<q->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val>p->val&&root->val>q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
    }
};