class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q; // maxheap
        int n=piles.size();
        for(int i=0;i<n;i++)
        q.push(piles[i]);

        while(k--){
            int x = q.top();
            q.pop();
            x=x-floor(x/2);
            q.push(x);
        }
        int ans=0;
        

        for(int i=0;i<n;i++){
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};