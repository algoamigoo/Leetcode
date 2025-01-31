class Solution {
public:
    bool canConstruct(string s, int k) {

        if(s.length()<k)
        return false;

        unordered_map<int,int> m;
        for(int i=0;i<s.length();i++)
        m[s[i]]++;

        int two=0,one=0;
        for(auto it : m)
        {
            two+=it.second/2;
            one+=it.second%2;
        }
        int mn=max(1,one--);

        if(k<mn)
        return false;

        return true;
    }
};