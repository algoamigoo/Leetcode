class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;    // Tracks maximum sum (positive)
        int minSum = 0;    // Tracks minimum sum (negative)
        int currMax = 0;   // Current maximum sum ending at current position
        int currMin = 0;   // Current minimum sum ending at current position
        
        for(int num : nums) {
            currMax = max(currMax + num, num);  
            currMin = min(currMin + num, num);
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        
        return max(maxSum, abs(minSum));
    }
};