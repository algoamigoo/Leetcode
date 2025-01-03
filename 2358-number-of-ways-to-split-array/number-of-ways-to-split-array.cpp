class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        double sum=0;
        for(int i=0;i<nums.size();i++)
        sum+=nums[i];

        double curr=0,c=0;
        for(int i=0;i<nums.size()-1;i++){
        curr+=nums[i];
        if(curr>=sum/2)
        {//cout<<curr<<" "<<i;
        c++;
        //cout<<endl;}
        }}
        return c;
    }
};