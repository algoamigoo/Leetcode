class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i =0,j=n-1;
        int sum;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        v.push_back({nums[i],i});
        
        sort(v.begin(),v.end());
        while(i<j){
            sum = v[i].first+v[j].first;
            if(sum>target)
            j--;
            else if(sum<target)
            i++;
            else
            break;
        }

        return {v[i].second,v[j].second};
    }
};