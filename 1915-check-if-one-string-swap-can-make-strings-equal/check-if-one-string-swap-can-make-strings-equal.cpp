class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])
            c++;
        }
        int m1[26],m2[26];
        
        for(int i=0;i<s1.size();i++){
            m1[s1[i]-'a']++;
            m2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(m1[i]!=m2[i])
            return false;
        }
        if(c==2 || c==0)
        return true;

        return false;

    }
};