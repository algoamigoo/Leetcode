class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int c=0,curr=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0 && (curr==sum/2 || curr==(sum+1)/2)){
                if(sum%2)
                c++;
                else
                c=c+2;
            }
            curr+=nums[i];
        }
        return c;
    }
};