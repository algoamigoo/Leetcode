/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void func(TreeNode* root, int mn, int mx, int& ans) {
        if (root == NULL)
            return;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        if (root->left == NULL && root->right == NULL)
            ans = max(ans, abs(mn - mx));

        func(root->left, mn, mx, ans);
        func(root->right, mn, mx, ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mn = root->val;
        int mx = root->val;
        int ans = 0;
        func(root, mn, mx, ans);

        return ans;
    }
};