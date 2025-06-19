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
    void func(TreeNode*& root, int val, int depth, int curr) {
        if (root == NULL)
            return;

        if (curr == depth - 1) {
            TreeNode* temp = root->left;
            TreeNode* temp2 = root->right;

            TreeNode* addLeft = new TreeNode(val); 
            TreeNode* addRight = new TreeNode(val); 

            root->left = addLeft;
            addLeft->left = temp;

            root->right = addRight;
            addRight->right = temp2;
        }

        func(root->left, val, depth, curr + 1);
        func(root->right,val, depth, curr + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* realroot = new TreeNode(val);
            realroot->left=root;
            realroot->right=NULL;
            return realroot; 
        }
        func(root,val, depth, 1);
        return root;
    }
};