class Solution {
public:
    int ans= 0; 
    
    int diameterOfBinaryTree(TreeNode* root) {
        fun(root); 
        return ans; 
    }
    
private:
    int fun(TreeNode* root) { 
        if (root == nullptr) return 0;
        
        int left = fun(root->left);
        int right = fun(root->right);
        
        ans= max(ans, left + right); 
        return max(left, right) + 1; 
    }
};
