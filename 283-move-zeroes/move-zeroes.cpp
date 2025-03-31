class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=nums.size()-1, i=0;
        int zerowindow=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zerowindow++;
            }
            else if(zerowindow>0){
                swap(nums[i-zerowindow],nums[i]);
            }
        }
        
    }
};