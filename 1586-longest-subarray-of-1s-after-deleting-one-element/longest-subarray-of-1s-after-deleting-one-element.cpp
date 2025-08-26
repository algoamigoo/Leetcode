class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> zero_idx;
        zero_idx.push_back(0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            zero_idx.push_back(i+1);
        }
        zero_idx.push_back(nums.size()+1);
        // 0 1 5 8 10
        int ans=0;
        if(zero_idx.size()<=2){
            ans=nums.size()-1;
        }
        for(int i=0;i<zero_idx.size()-2;i++){
            ans=max(zero_idx[i+2]-zero_idx[i]-2,ans);
        }
        return ans;
    }
};