
/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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

class Codec {
public:
    void rserialize(TreeNode* root,string& str)
    {
        if(root == nullptr)
            str += "None,";
        else
        {
            str += to_string(root->val) + ",";
            rserialize(root->left,str);
            rserialize(root->right,str);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string result;
        rserialize(root,result);
        return result;
    }

    TreeNode* rdeserializa(list<string>& datalist)
    {
        if(datalist.front() == "None")
        {
            datalist.erase(datalist.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(datalist.front()));
        datalist.erase(datalist.begin());
        root->left = rdeserializa(datalist);
        root->right = rdeserializa(datalist);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        list<string> datalist;
        string str;
        for(auto c : data)
        {
            if(c == ',')
            {
                datalist.push_back(str);
                str.clear();
            }
            else
                str += c;
        }
        if(!str.empty())
        {
            datalist.push_back(str);
            str.clear();
        }
        return rdeserializa(datalist);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

