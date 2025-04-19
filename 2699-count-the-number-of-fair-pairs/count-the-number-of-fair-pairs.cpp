class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long c=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int curr = nums[i];
            auto lb = lower_bound(nums.begin()+i+1,nums.end(),lower-curr);
            auto ub = upper_bound(nums.begin()+i+1,nums.end(),upper-curr);
            c+=ub-lb;
        }
        return c;
    }
};