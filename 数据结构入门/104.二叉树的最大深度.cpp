/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) 
    {
        queue<TreeNode*> bfs;        
        int count = 0;
        if(root != nullptr)
        {
            bfs.push(root);
        }
        while(!bfs.empty())
        {
            int n = bfs.size();
            for(int i = 0;i < n;i++)
            {
                auto temp = bfs.front();
                bfs.pop();
                if(temp->left != nullptr)
                    bfs.push(temp->left);
                if(temp->right != nullptr)
                    bfs.push(temp->right);
            }
            count++;
        }
        return count;
    }
};
// @lc code=end

