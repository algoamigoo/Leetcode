class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s;
        for(auto it : banned)
        s.insert(it);
        int sum=0,c=0;
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end())
            {
            if(sum + i > maxSum)
            break;
            sum+=i;
            c++;
            }
        }
        return c;
    }
};