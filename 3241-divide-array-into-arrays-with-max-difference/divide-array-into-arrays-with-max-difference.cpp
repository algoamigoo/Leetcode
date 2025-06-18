class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i=i+3){
            int x = nums[i];
            int y = nums[i+1];
            int z = nums[i+2];
            if(z-x<=k){
                ans.push_back({x,y,z});
            }
            else{
                return {};
            }
        }
        return ans;
    }
};