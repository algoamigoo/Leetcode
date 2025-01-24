class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int i=0,n=a.size();
        vector<int> ans;
        int c=0;
        unordered_set<int> s;
        for(i=0;i<n;i++){
            s.insert(a[i]);
            s.insert(b[i]);
            c=(i+1)*2-s.size();
            ans.push_back(c);
        }
            return ans;
    }
};