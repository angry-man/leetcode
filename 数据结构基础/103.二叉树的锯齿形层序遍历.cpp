/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root == nullptr)
            return vector<vector<int>>{};
        deque<TreeNode*> q;
        q.push_back(root);
        bool flag = false;  // true为从左往右
        vector<vector<int>> result;
        while(!q.empty())
        {
            vector<int> state;
            int n = q.size();
            for(int i = 0;i < n; ++i)
            {
                if(flag)
                {
                    auto temp = q.front();
                    q.pop_front();
                    state.emplace_back(temp->val);
                    if(temp->right != nullptr)
                        q.push_back(temp->right);
                    if(temp->left != nullptr)
                        q.push_back(temp->left);
                }
                else
                {
                    auto temp = q.back();
                    q.pop_back();
                    state.emplace_back(temp->val);
                    if(temp->left != nullptr)
                        q.push_front(temp->left);
                    if(temp->right != nullptr)
                        q.push_front(temp->right);                         
                }               
            }
            flag = !flag;
            result.emplace_back(state);
        }
        return result;
    }
};
// @lc code=end

