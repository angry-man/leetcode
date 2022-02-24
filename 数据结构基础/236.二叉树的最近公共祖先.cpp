/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* result;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        DFS(root,p,q);
        return result;
    }

    bool DFS(TreeNode* root, TreeNode* p, TreeNode* q)
    //p, q是不是root的子节点
    {
        if(root == nullptr)
            return false;
        bool lson = DFS(root->left,p,q);//p,q是不是左子树的子节点；
        bool rson = DFS(root->right,p,q);//p,q是不是右子树的节点；
        if((lson && rson)||((root->val == p->val || root->val == q->val) && (lson || rson)))
            result = root;
        //要么是左子节点，要么是右子节点，要么自身就是p,q节点；
        return lson || rson || (root->val == p->val || root->val == q->val);
    }
};
// @lc code=end

