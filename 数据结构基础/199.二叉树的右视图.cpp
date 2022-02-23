/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == nullptr)
            return vector<int> {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while(!q.empty())
        {
            int n = q.size();
            result.push_back(q.front()->val);
            for(int i = 0; i < n;++i)
            {
                auto temp = q.front();
                q.pop();
                if(temp->right != nullptr)
                    q.push(temp->right);
                if(temp->left != nullptr)
                    q.push(temp->left);               
            }
        }
        return result;
    }
};
// @lc code=end

