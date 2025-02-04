class Solution {
    bool f(vector<int>& nums,int x,int t){
        int n= nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((nums[i]*1.0)/x);
        }
        if(sum<=t)
        return true;

        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int l=1,h= 1e6;
        int ans=0;
        while(l<=h){
            int mid = (l+h)/2;
            if(f(nums,mid,t)){
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};