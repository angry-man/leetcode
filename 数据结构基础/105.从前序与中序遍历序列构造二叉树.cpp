/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int,int> index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n = inorder.size();
        for(int i = 0;i < n;++i)
            index[inorder[i]] = i;
        return Tree(preorder,inorder,0,n - 1,0,n - 1);
    }
    TreeNode* Tree(vector<int>& preorder,vector<int>& inorder,
                    int preleft,int preright,
                    int inleft,int inright)
    {
        if(preleft > preright)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preleft]);
        int inroot = index[preorder[preleft]];
        int left_size = inroot - inleft;
        root->left = Tree(preorder,inorder,
                         preleft + 1,preleft + left_size,
                         inleft,inroot -1);
        root->right = Tree(preorder,inorder,
                          preleft + left_size + 1,preright,
                          inroot + 1,inright);
        return root;
    }
};
// @lc code=end

