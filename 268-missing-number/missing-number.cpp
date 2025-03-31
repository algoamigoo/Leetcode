class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int t = 0, i = 0;
	for (i = 0; i < nums.size(); i++) {
		t = t ^ i ^ nums[i];
	}

	return t ^ i;
    }
};