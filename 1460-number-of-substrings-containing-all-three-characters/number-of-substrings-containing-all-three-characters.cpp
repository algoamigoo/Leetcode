class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0 , r = 0 , end = s.size() - 1;
        unordered_map<char,int> m;
        int c = 0;
        
        while(r != s.size())
        {
            m[s[r]] += 1;
            while(m['a'] && m['b'] && m['c']) 
            {
                c += 1 + (end - r);
                m[s[l]] -= 1; 
                l++;
            }
            r++;
        }
        return c;
    }
};