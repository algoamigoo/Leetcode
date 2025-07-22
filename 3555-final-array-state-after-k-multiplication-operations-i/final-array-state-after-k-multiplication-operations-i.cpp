class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // min heap
         for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
         }

         while(k>0){
            int x = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            pq.push({x*multiplier,i});
            k--;
         }
         vector<pair<int,int>> ans;
         while(!pq.empty())
         {  
            int x = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            ans.push_back({x,i});
         }
         vector<int> numbers;
         sort(ans.begin(),ans.end(),cmp);
         for(int i=0;i<n;i++){
            numbers.push_back(ans[i].first);
         }
         return numbers;
    }
};