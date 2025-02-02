class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        int n=v.size();
        unordered_map<int,int> f;
        for(int i=0;i<n;i++)
        f[v[i]]++;
        vector<int> ans;
        
        priority_queue<pair<int,int>> q;
        for(auto it : f)
        q.push({it.second,it.first});

        while(k--){
            int x = q.top().second;
            ans.push_back(x);
            q.pop();
        }
        return ans;
    }
};