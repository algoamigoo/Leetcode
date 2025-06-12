class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) 
        return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        
        bool rev = false;
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            if (rev) reverse(temp.begin(), temp.end());
            res.push_back(temp);
            rev = !rev;
        }
        return res;
    }
};
