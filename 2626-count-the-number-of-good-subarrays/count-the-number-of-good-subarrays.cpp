class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size(),j=0;
        unordered_map<int,int> mp;
        long long ans=0;
        long long sum=0;

         for(int i=0;i<n;i++){
            while(j<n&&sum<k){
              long long cn= mp[nums[j]];
              long long prev=1LL*cn*(cn-1)/2;
              mp[nums[j]]++;
              j++;
              sum+=(1LL*cn*(cn+1)/2)-prev;
            }
            if(sum>=k)
            ans+=n-j+1;
            long long cn= mp[nums[i]];
            long long prev=1LL*cn*(cn-1)/2;
            sum+=(1LL*(cn-2)*(cn-1)/2)-prev;
            mp[nums[i]]--;
        }
        return ans;

    }
};