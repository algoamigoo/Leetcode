
class Solution {
public:
    void solve(TreeNode* root, vector<int>& nums) {
        if (!root)
            return;

        solve(root->left, nums);
        nums.push_back(root->val);
        solve(root->right, nums);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> nums;
        solve(root, nums);
        map<int,int> m;
        for(auto it : nums)
        m[it]++;
        int mx=0;
        vector<int> ans;
        for(auto it : m){
            mx=max(mx,it.second);
        }
        for(auto it : m)
        {
            if(it.second==mx)
            ans.push_back(it.first);
        }
        return ans;
    }
};