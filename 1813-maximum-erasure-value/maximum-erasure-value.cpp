class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        set<int> s;
        int sum = 0, ans = 0;
        while (i < n) {
            if (s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
                sum += nums[i];
                i++;
                ans = max(ans, sum);
            } else {
                while (nums[j] != nums[i]) {
                    sum -= nums[j];
                    s.erase(nums[j]);
                    j++;
                }
                sum-=nums[j];
                s.erase(nums[j]); 
                j++;
            }
        }
        return ans;
    }
};