class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        vector<pair<int,int>> nodes;
        int n = s.size();
        for (int i = 0; i < n;) {
            int depth = 0;
            while (i < n && s[i] == '-') {
                depth++;
                i++;
            }
            string num = "";
            while (i < n && s[i] != '-') {
                num += s[i++];
            }
            int value = stoi(num);
            nodes.push_back({value, depth});
        }
        
        int index = 0;
        return buildTree(nodes, index, 0);
    }
    
private:
    TreeNode* buildTree(vector<pair<int,int>>& nodes, int& index, int depth) {
        if (index >= nodes.size() || nodes[index].second != depth) {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(nodes[index].first);
        index++;
        
        node->left = buildTree(nodes, index, depth + 1);
        node->right = buildTree(nodes, index, depth + 1);
        
        return node;
    }
};