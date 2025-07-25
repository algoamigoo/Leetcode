class Solution {
public:
    int n;
     int backtrack(int i,vector<int> & nums,int sum){
        if(i==n)
        return sum;

        return backtrack(i+1,nums,sum^nums[i])+backtrack(i+1,nums,sum);

    }
    int subsetXORSum(vector<int>& nums) {
        // xor twice to cancel xor use backtracking
        n=nums.size();
        int sum=0;
        return backtrack(0,nums,0);

    }
};