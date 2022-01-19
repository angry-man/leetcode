// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem114.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) 
    {
        if(root == nullptr)
            return ;
        TreeNode* Right = nullptr;
        TreeNode* Left = nullptr;
        if(root->left != nullptr)
        {
            flatten(root->left);
            Left = root->left;
        }

        if(root->right != nullptr)
        {
            flatten(root->right);
            Right = root->right;
        }
            
        if(Left != nullptr)
        {
            root->right = Left;  
            while(Left != nullptr && Left->right != nullptr)
                Left = Left->right; 
            Left->right = Right;
            root->left = nullptr;
        }
        
    }
};
// @lc code=end

