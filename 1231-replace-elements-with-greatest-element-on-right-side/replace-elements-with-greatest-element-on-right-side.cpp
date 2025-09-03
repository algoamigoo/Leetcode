class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx=0,n=arr.size();
        vector<int> ans;
        ans.push_back(-1);
        for(int i=n-1;i>=1;i--){
            mx=max(mx,arr[i]);
            ans.push_back(mx);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};