class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> preMax(n), sufMax(n);
        
        // Build prefix max array
        preMax[0] = nums[0];
        for(int i = 1; i < n; i++) {
            preMax[i] = max(preMax[i-1], nums[i]);
        }
        
        // Build suffix max array
        sufMax[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            sufMax[i] = max(sufMax[i+1], nums[i]);
        }
        
        // Find max triplet value using j as middle index
        long long maxVal = 0;
        for(int j = 1; j < n-1; j++) {
            if(preMax[j-1] > nums[j]) {
                maxVal = max(maxVal, (long long)(preMax[j-1] - nums[j]) * sufMax[j+1]);
            }
        }
        
        return maxVal;
    }
};