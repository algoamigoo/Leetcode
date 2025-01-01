class Solution {
public:
    // 1st Jan 2025
    // binary search
    // 11:25
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        int mid=(l+h)/2;

        while(l<=h){
            mid=(l+h)/2;
            if(nums[mid]<target)
            l=mid+1;
            else if(nums[mid]>target)
            h=mid-1;
            else
            return mid;
        }
        return -1;
    }
};