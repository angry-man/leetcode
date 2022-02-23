/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == nullptr)
            return nullptr;
        if(root->val == key)
        {
            if(root->left == nullptr)
                return root->right;
            else if(root->right == nullptr)
                return root->left;
            else
            {
                auto temp = root->right;
                while(temp->left != nullptr)
                    temp = temp->left;
                temp->left = root->left;
                return root->right;
            }
        }
        else if(root->val < key)
            root->right = deleteNode(root->right,key);
        else 
            root->left = deleteNode(root->left, key);
        return root;
    }
};
// @lc code=end

