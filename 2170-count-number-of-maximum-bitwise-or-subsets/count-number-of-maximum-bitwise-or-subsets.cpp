class Solution {
public:
    int func(int ind, int curr, vector<int>& nums, int ans){
        {
            if(ind==nums.size()){
                if(ans==curr)
                return 1;
                return 0;
            }
        }
        return (func(ind+1,curr,nums,ans)+func(ind+1,curr|nums[ind],nums,ans));
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans|nums[i];
        }
        return func(0,0,nums,ans);
    }
};