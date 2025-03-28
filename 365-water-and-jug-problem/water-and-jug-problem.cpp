class Solution {
public:
    bool canMeasureWater(int a, int b, int target) {
        /*
        we will check the possible states
        operations
        1. pour form a to b
        2. pour form b to a
        3. empty a
        4. empty b
        5. fully fill a
        6. fully fill b
        */
        set<pair<int,int>> used_states;
        queue<pair<int,int>> q;
        q.push({0,0});
        int sum=0;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            sum=x+y;
            if(sum==target)
            return true;
            
            vector<pair<int,int>> v;
            v.push_back({0,x});
            v.push_back({y,0});
            v.push_back({max(0,a-x),min(b,y+x)});
            v.push_back({min(a,x+y),max(0,b-y)});
            v.push_back({a,y});
            v.push_back({x,b});

            for(auto it : v){
                if(used_states.count(it)==0)
                {
                    q.push(it);
                    used_states.insert(it);
                }
            }
        }
        return false;
    }
};