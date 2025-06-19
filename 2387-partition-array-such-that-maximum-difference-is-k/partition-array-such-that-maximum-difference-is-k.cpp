class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int curr_mn=nums[0],n=nums.size(),c=1,i=0;

        while(i<n){
            if(nums[i]-curr_mn<=k)
            i++;
            else{
                c++;
                curr_mn=nums[i];
                i++;
            }
        }
        return c;
    }
};