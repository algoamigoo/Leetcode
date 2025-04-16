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
    vector<int> preorder;
    void pre(TreeNode* root){
        if (!root) return;
        preorder.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
    void flatten(TreeNode* root) {
        // bruteforce
        // preorder traversal
        // store in a vector
        // re traverse to rearrange
        if (!root) return;
        pre(root);
        int i = 1;
        TreeNode* curr = root;
        curr->left = NULL;
        while(i < preorder.size()){
            curr->right = new TreeNode(preorder[i]);
            curr = curr->right;
            curr->left = NULL;
            i++;
        }
    }
};