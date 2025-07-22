class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // min heap, smallest at top
        //priority_queue<pair<int,int>> pq;

        for(int i=0;i<points.size();i++){
            int dis = points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dis,i});
        }
        vector<vector<int>> ans;
        int count=0;
        vector<int> indices;
        while(count!=k){
            int i = pq.top().second;
            pq.pop();
            indices.push_back(i);
            count++;
        }
        for(int i=0;i<indices.size();i++)
        ans.push_back(points[indices[i]]);

        return ans;
    }
};