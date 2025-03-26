class Solution {
public:
    int n;
    int t[2501][2501];
    int lis(vector<int>& nums, int p, int i) {
       if(i == n)
           return 0;
        
        if(p != -1 && t[p][i] != -1)
            return t[p][i];
        
        int take = 0;
        if(p == -1 || nums[i] > nums[p])
            take = 1 + lis(nums, i, i+1);
        
        int not_take = lis(nums, p, i+1);
        
        if(p != -1)
            t[p][i] =  max(take, not_take);
        
        return max(take, not_take);
            
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        n = nums.size();
        return lis(nums, -1, 0);
    }
};