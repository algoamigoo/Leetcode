class Solution {
public:
    void solve(TreeNode* root,vector<int>&nums){
        if(!root) return;

        solve(root->left,nums);
        nums.push_back(root->val);
        solve(root->right,nums);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>nums;
        solve(root,nums);
        int minDiff=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            minDiff=min(minDiff,abs(nums[i]-nums[i+1]));
        }
        return minDiff;
    }
};