class Solution {
public:
    bool check(vector<int>& v) {
        int n=v.size(),c=0;
        for(int i=0;i<n-1;i++){
            if(v[i]>v[i+1])
            c++;
        }
        if(c==0)
        return true;

        if(c==1 && v[n-1]<=v[0])
        return true;

        return false;
    }
};