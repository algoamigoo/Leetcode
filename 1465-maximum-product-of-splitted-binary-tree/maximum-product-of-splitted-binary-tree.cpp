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
    const int mod = 1e9 + 7;
    
    long long func(TreeNode* root, vector<long long>& v) {
        if (root == nullptr) {
            return 0;
        }
        
        long long leftSum = func(root->left, v);
        long long rightSum = func(root->right, v);
        
        long long subtreeSum = leftSum + rightSum + root->val;
        
        v.push_back(subtreeSum);
        
        return subtreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        // calc total sum,
        // calculate inner sum
        // find innersum*(totalsum-innersum)
        // keep track of max, do for each index
        vector<long long> v;
        long long total = func(root, v);
        
        long long ans = 0;
        
        for (long long inner : v) {
                long long product = (inner * (total - inner));
                ans = max(ans, product);
        }
        
        return ans % mod;
    }
};