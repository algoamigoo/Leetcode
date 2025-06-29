class Solution {
public:
    long long mod=1e9 + 7;
    long long binpow(long long a, long long b, long long m) {
    if (b == 0) return 1;
    long long res = binpow(a, b / 2, m);
    res = res * res % m;
    if (b % 2) res = res * a % m;
    return res;
}
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        long long c=0;
        // 3 5 6
        // 3c1+3c2+3c3 = 1+3+3
        if(nums[l]*2>target)
        return 0;
        while(l<r){
            while(nums[l]+nums[r]>target)
            r--;
            if(l<=r && nums[l]+nums[r]<=target)
            c+=binpow(2,r-l,mod)%mod;
            l++;
            if(l==r && nums[l]+nums[r]<=target)
            c++;
        }
        c=c%mod;
        int ans = (int)c; 
        return ans;
    }
};