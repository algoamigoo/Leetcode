class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b){
        if(a.second<b.second)
        return true;

        return false;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        v.resize(k);
        sort(v.begin(),v.end(),cmp);

        vector<int> ans;
        for(int i=0;i<k;i++)
        ans.push_back(v[i].first);

        return ans;
    }
};