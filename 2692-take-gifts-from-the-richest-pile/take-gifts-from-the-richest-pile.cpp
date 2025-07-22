class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
         priority_queue<int> pq(gifts.begin(),gifts.end());
         while(k>0){
            long long big_pile = pq.top();
            pq.pop();
            big_pile = sqrtl(big_pile);
            pq.push(big_pile);
            k--;
         }
         long long ans=0;
         while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
         }
         return ans;
    }
};