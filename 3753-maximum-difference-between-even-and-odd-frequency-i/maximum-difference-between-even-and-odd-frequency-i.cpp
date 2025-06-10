class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int,int> m;
        for(auto it : s){
            m[it]++;
        }
        int mxodd=0,mxeven=0,mnodd=INT_MAX,mneven=INT_MAX;
        for(auto it : m){
            if(it.second%2)
            {mxodd=max(mxodd,it.second);
            }
            else{
            mneven =min(mneven,it.second);
            }
        }
        return mxodd-mneven;
    }
};