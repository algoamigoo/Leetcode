class Solution {
public:
    int appendCharacters(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        int i=0,j=0;
        while(i<slen){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else
            i++;
            if(j==tlen)
            return 0;
        }
        return tlen-j;
    }
};