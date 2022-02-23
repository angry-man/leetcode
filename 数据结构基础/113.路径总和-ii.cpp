/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> state;
        path(root,targetSum,state);
        return result;
    }

    void path(TreeNode* root, int targetSum,vector<int> state)
    {
        if(root == nullptr)
            return ;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(root->val == targetSum)
            {
                state.emplace_back(root->val);
                result.emplace_back(state);
                state.pop_back();
            }
            return ;
        }

        state.emplace_back(root->val);
        path(root->left,targetSum - root->val,state);

        path(root->right,targetSum - root->val,state);
        state.pop_back();
        
    }
};
// @lc code=end

