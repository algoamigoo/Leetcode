#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    bool isPossible(std::vector<int>& nums) {
        // Map to store frequency of each number
        std::unordered_map<int, int> freq;
        // Map to store the count of subsequences ending at each number
        std::unordered_map<int, int> tails;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Process each number in the array
        for (int num : nums) {
            // Skip if we've used this number
            if (freq[num] == 0) continue;
            
            // Case 1: Append to existing subsequence
            if (tails[num - 1] > 0) {
                tails[num - 1]--;  // Remove one subsequence ending at num-1
                tails[num]++;      // Add one subsequence ending at num
                freq[num]--;       // Use up one occurrence of num
            }
            // Case 2: Start new subsequence (need at least 3 numbers)
            else if (freq[num] > 0 && freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num]--;      // Use one num
                freq[num + 1]--;  // Use one num+1
                freq[num + 2]--;  // Use one num+2
                tails[num + 2]++; // New subsequence ends at num+2
            }
            else {
                return false;
            }
        }
        
        return true;
    }
};