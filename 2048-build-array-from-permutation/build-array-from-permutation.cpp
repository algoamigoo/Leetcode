class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        int N=nums.size();
        for(int i=0;i<N;i++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};