
class Solution {
public:
    TreeNode* func(int& i, vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int, int>& mp) {
        // Base case: if no elements to process
        if (start > end) return nullptr;
        
        // Create new root node with current preorder value
        TreeNode* root = new TreeNode(preorder[i]);
        int idx = mp[preorder[i]];
        i++; // Move to next preorder element
        
        // Recursively build left and right subtrees
        root->left = func(i, preorder, inorder, start, idx - 1, mp);
        root->right = func(i, preorder, inorder, idx + 1, end, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create hash map for inorder value -> index
        unordered_map<int, int> mp;
        for (int j = 0; j < inorder.size(); j++) {
            mp[inorder[j]] = j;
        }
        
        int n = preorder.size();
        int i = 0, start = 0, end = n - 1;
        return func(i, preorder, inorder, start, end, mp);
    }
};