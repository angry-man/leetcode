/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> bfs;        
        vector<vector<int>> result;
        if(root != nullptr)
        {
            bfs.push(root);
        }
        while(!bfs.empty())
        {
            vector<int> state;
            int n = bfs.size();
            for(int i = 0;i < n;i++)
            {
                auto temp = bfs.front();
                bfs.pop();
                state.push_back(temp->val);
                if(temp->left != nullptr)
                    bfs.push(temp->left);
                if(temp->right != nullptr)
                    bfs.push(temp->right);
            }
            result.push_back(state);
        }
        return result;
    }
};
// @lc code=end

