/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) 
    {
        if(root->left == nullptr && root->right == nullptr)
            return true;
        else if(root != nullptr && root->left != nullptr && root->right != nullptr)
        {
            return symmetric(root->left,root->right);
        }
        return false;
    }

    bool symmetric(TreeNode* root1,TreeNode* root2)
    {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 != nullptr && root2 != nullptr && root1->val == root2->val)
        {
            return symmetric(root1->left,root2->right) && 
                    symmetric(root1->right,root2->left);
        }
        return false;
    }
};
// @lc code=end

