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

    void dfs(TreeNode* root, bool& OutIsBalanced, int& OutHeight)
    {
        if(root == nullptr)
        {
            OutIsBalanced = true;
            OutHeight = 0;
            return;
        }

        int LeftHeight = 0;
        int RightHeight = 0;
        bool IsLeftBalanced = false;
        bool IsRightBalanced = false;
        dfs(root->left, IsLeftBalanced, LeftHeight);
        dfs(root->right, IsRightBalanced, RightHeight);

        OutIsBalanced = IsLeftBalanced && IsRightBalanced && abs(LeftHeight - RightHeight) <= 1;
        OutHeight = 1 + max(LeftHeight, RightHeight);
    }

    bool isBalanced(TreeNode* root) {
        
        bool IsBalanced = false;
        int Height = 0;
        dfs(root, IsBalanced, Height);
        return IsBalanced;
    }
};
