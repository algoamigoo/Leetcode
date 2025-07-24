class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> p;
        for(int i=0;i<n;i++){
            p.push_back({static_cast<double>(wage[i]) / quality[i], quality[i]});;
        }
        sort(p.begin(),p.end()); // sort by quality/wage
        double ans=DBL_MAX;
        double curr=0;
         // Use a priority queue to keep track of the highest quality workers
        priority_queue<int> q;
        for(int i=0;i<n;i++){
            q.push(p[i].second);
            curr+=p[i].second;
            // If we have more than k workers,
            // remove the one with the highest quality
            if(q.size()>k){
                curr-=q.top();
                q.pop();
            }
            if(q.size()==k)
            ans=min(ans,curr*p[i].first);
        }
        return ans;

    }
};