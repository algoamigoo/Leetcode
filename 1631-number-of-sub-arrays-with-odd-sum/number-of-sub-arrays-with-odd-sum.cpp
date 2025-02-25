class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        int oddCount = 0;  // count of subarrays ending at current position with odd sum
        int evenCount = 0; // count of subarrays ending at current position with even sum
        int currSum = 0;   // running sum
        
        for(int num : arr) {
            currSum += num;
            
            // If current sum is odd
            if(currSum % 2) {
                // Add all even-sum subarrays before this (they become odd when combined)
                // Plus 1 for the single element subarray
                result = (result + evenCount + 1) % MOD;
                oddCount++;
            } 
            // If current sum is even
            else {
                // Add all odd-sum subarrays before this (they become odd when combined)
                result = (result + oddCount) % MOD;
                evenCount++;
            }
        }
        
        return result;
    }
};