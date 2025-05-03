class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
     map<int,int> m;
     for(int i=0;i<tops.size();i++){
        if(tops[i]==bottoms[i])
        m[tops[i]]++;
        else{
            m[tops[i]]++;
            m[bottoms[i]]++;
        }
     }   
        set<int> s;
        for(auto it : m){
            if(it.second>=tops.size())
            s.insert(it.first);
        }
        int ans=INT_MAX;
        int c=0;
        for(auto it : s){
            for(int i=0;i<tops.size();i++){
                if(tops[i]==it)
                c++;
            }
            c = min(c, (int)tops.size() - c);
            ans=min(ans,c);
            c=0;
        } 
        for(auto it : s){
            for(int i=0;i<tops.size();i++){
                if(bottoms[i]==it)
                c++;
            }
            c = min(c, (int)bottoms.size() - c);
            ans=min(ans,c);
            c=0;
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};