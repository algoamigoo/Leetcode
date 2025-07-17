class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size(),odd=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2)
            {nums[i]=1;
            odd++;}
            else
            nums[i]=0;
        }
        int even = n-odd;
        // e e e e e 
        // o e o e
        // e o e o
        // o o o o 
        int ans = max(even,odd);
        int prev = 1;
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=prev){
                c++;
                prev=prev^1;
            }
        }
        ans = max(c,ans);
        prev =0;
        c=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=prev){
                c++;
                prev=prev^1;
            }
        }
        ans=max(c,ans);
        return ans;
    }
};