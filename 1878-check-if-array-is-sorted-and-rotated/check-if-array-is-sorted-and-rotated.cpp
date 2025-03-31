class Solution {
public:
    bool check(vector<int>& v) {
        int c=0;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1])
            c++;
        }
        if(v[v.size()-1]>v[0])
        c++;
        if(c<=1)
        return true;
        return false;
    }
};