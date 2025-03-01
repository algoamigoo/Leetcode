class Solution {
public:
    long long func(int n) {
        unordered_map<int,int> m;
        while (n % 2 == 0) {
            m[2]++;
            n = n/2; 
        } 
        for (int i = 3; i*i <= n; i = i + 2) {
            while (n % i == 0) {
                m[i]++;
                n = n/i; 
            } 
        }
        if (n > 2) {
            m[n]++;
        }
        long long ans = 1;
        for(auto it: m) {
            if(it.second % 2 == 1) { 
                ans = ans * it.first;
            }
        }
        return ans;
    } 

    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,long long> m;
        
        for(int i = 1; i <= n; i++) {
            m[func(i)] += nums[i-1];
        }

        long long ans = 0;
        for(auto it : m) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};