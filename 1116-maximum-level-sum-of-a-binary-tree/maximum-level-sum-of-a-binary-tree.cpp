class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;    // From your original code
        int lvl = 0;        // From your original code
        
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            sums.push_back(levelSum);
            lvl++;                    
        }
        
        int mx = sums[0];
        int ans = 1;
        
        for (int i = 1; i < sums.size(); i++) {
            if (sums[i] > mx) {
                mx = sums[i];
                ans = i + 1;
            }
        }
        
        return ans;
    }
};