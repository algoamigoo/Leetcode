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
    void findPaths(TreeNode* root, int targetSum, int currSum, vector<int>& temp, vector<vector<int>>& ans) {
        
        if (root == nullptr)
        return;
        
        
        temp.push_back(root->val);
        currSum += root->val;
        
        if (root->left == nullptr && root->right == nullptr && currSum == targetSum) {
            ans.push_back(temp);
        }
        
        findPaths(root->left, targetSum, currSum, temp, ans);
        findPaths(root->right, targetSum, currSum, temp, ans);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;      
        findPaths(root, targetSum, 0, temp, ans);
        return ans;
    }
};