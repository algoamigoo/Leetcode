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
    bool findPaths(TreeNode* root, int targetSum, int currSum) {
        
        if (root == nullptr)
        return false;
        
        currSum += root->val;
        
        if (root->left == nullptr && root->right == nullptr && currSum == targetSum) {
            return true;
        }
        
        return findPaths(root->left, targetSum, currSum) || 
               findPaths(root->right, targetSum, currSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return findPaths(root, targetSum, 0);
    }
};