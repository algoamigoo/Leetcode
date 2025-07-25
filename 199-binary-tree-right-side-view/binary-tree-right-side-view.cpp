
class Solution {
public:
    void preOrder(TreeNode* root, int level, vector<int>& result) {
        if (root == NULL)
        return;

        if (result.size() < level) {
        result.push_back(root->val);}

        preOrder(root->right, level + 1, result);
        preOrder(root->left, level+1, result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        preOrder(root, 1, result);
        return result;
        }
};