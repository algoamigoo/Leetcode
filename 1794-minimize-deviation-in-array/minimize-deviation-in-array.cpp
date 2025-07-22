class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // 4,1,5,20,3
        // 4,2,10,20,6
        // 2 4 6 10 20
        // 2,4,3,5,5 
        priority_queue<int> mx; // biggest at top
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
            {
                mx.push(nums[i]);
            }
            else{
                mx.push(nums[i]*2);
            }
            if(nums[i]%2)
            mn=min(mn,nums[i]*2);
            else
            mn=min(mn,nums[i]);
        }
        int ans=mx.top()-mn;
        while(mx.top()%2==0){
            int x = mx.top();
            mx.pop();
            x=x/2;
            mn=min(mn,x);
            mx.push(x);
            ans=min(ans,mx.top()-mn);
        }
        return ans;
    }
};