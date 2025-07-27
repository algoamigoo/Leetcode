class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        for(int i=1;i<n-1;i++){
            while(nums[i]==nums[i-1])
            i++;
            int left = 0,right = 0;
            for(int l=i-1;l>=0;l--){
                if(nums[l]!=nums[i])
                {
                    left = nums[l];
                    break;
                }
            }

            for(int r=i+1;r<n;r++){
                if(nums[r]!=nums[i]){
                    right=nums[r];
                    break;
                }
            }
            if(left==0 || right==0)
            i++;
            else if((left<nums[i] && right<nums[i]) || (left>nums[i] && right>nums[i]))
            ans++;
        }
        return ans;
    }
};