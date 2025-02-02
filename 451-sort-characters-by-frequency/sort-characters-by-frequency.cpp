class Solution {
public:
    string frequencySort(string s) {
        // maxheap
        priority_queue<pair<int,char>> pq;
        int n=s.length();
        unordered_map<char,int> f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        for(int i=0;i<n;i++){
            pq.push({f[s[i]],s[i]});
        }
        string ans="";
        for(int i=0;i<n;i++){
            char c = pq.top().second;
            pq.pop();
            ans+=c;
        }
        return ans;
    }
};