class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low=nums[0],mid=INT_MAX,high=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<low)
            low=nums[i];
            else if(nums[i]>low && nums[i]<mid)
            mid=nums[i];

            if(nums[i]>mid && mid!=INT_MAX)
            return true;
        }
        return false;
    }
};