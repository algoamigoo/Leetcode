class Solution {
public:
    
    bool f(vector<int>& nums,int wt,int days){
        int n= nums.size(),c=1;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(wt<nums[i])
            return false;
        }
        long long mx=INT_MAX;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=wt)
            sum+=nums[i];
            else
            {
                c++;
                sum=nums[i];
            }
            mx=min(sum,mx);
        }

        if(mx<=wt && c<=days)
        return true;

        return false;
    }
    int splitArray(vector<int>& nums, int days) {
        
        int l=0,h= 1e9;
        int ans=0;
        while(l<=h){
            int mid = (l+h)/2;
            if(f(nums,mid,days)){
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};