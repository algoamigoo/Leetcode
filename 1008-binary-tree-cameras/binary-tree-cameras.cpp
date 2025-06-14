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
private:
    int cameras = 0; // Initialize cameras

    // States:
    // 1: Has camera
    // 0: Covered, no camera
    // -1: Not covered, no camera
    int func(TreeNode* root) {
        if (root == NULL) return 0; // Null nodes are covered

        // Check for leaf node
        if (root->left == NULL && root->right == NULL) return -1; // Leaf is not covered

        // Process left and right children
        int l = func(root->left);
        int r = func(root->right);

        // If any child is not covered, place a camera here
        if (l == -1 || r == -1) {
            cameras++;
            return 1; // Node has a camera
        }
        // If any child has a camera, this node is covered
        if (l == 1 || r == 1) {
            return 0; // Node is covered, no camera
        }
        // Both children are covered, this node is not covered
        return -1; // Node needs coverage from parent
    }

public:
    int minCameraCover(TreeNode* root) {
        if (root == NULL) return 0; // Empty tree needs no cameras

        // Process the tree
        int rootState = func(root);
        // If root is not covered, add a camera
        if (rootState == -1) cameras++;
        return cameras;
    }
};