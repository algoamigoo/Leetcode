class Solution {
public:
    // lower bound of x gives the number greater than or equal to x
    // upper bound of x gives the number smaller than x
    int lastocc(vector<int>& nums, int x){
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > x)
            high = mid- 1;
            else{
                if(nums[mid]==x)
                ans=mid;
                low=mid+1;
            }
        }
            return ans;
    }

    int firstocc(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (x > nums[mid])
                low = mid + 1; 
            else {
                if(nums[mid]==x)
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int x) {
        vector<int> v;
        v.push_back(firstocc(nums, x));
        v.push_back(lastocc(nums, x));

        return v;
    }
};