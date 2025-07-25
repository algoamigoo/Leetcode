class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void backtrack(int i,vector<int>& nums,vector<int> temp){
        if(i==n)
        {ans.push_back(temp);
        return;};
        
        //backtrack
        backtrack(i+1,nums,temp);
        temp.push_back(nums[i]);
        backtrack(i+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        backtrack(0,nums,temp);

        return ans;
    }
};