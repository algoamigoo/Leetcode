class Solution {
public:
    void backtrack(set<vector<int>> &ans,int i, vector<int>&nums,vector<int> curr){
            if(curr.size()==0 || curr.back()<=nums[i])
            {curr.push_back(nums[i]);}

            if(curr.size()>=2)
            ans.insert(curr);

            if(i+1<nums.size())
            backtrack(ans,i+1,nums,curr);

            if(curr.size()>=2)
            {curr.pop_back();
            if(i+1<nums.size())
            backtrack(ans,i+1,nums,curr);}

            return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;

        for(int i=0;i<nums.size()-1;i++){
        vector<int> curr;
        backtrack(ans,i,nums,curr);
        }
        vector<vector<int>> v;
        for(auto it : ans){
            v.push_back(it);
        }
        return v;
    }
};