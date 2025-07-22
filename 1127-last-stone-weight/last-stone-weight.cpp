// soln 1

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q; // store max at top, max heap
        for(auto stone : stones){
            q.push(stone);
        }
        while(q.size()>=2){
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if(y>x)
            q.push(y-x);
        }
        int y = q.top(),x=0;
        q.pop();
        if(q.size()>0)
        x=q.top();

        return y-x;
    }
};