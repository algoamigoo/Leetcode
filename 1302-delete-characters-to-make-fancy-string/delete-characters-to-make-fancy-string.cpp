class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int c=1;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]!=s[i+1])
            c=1;
            else
            c++;

            if(c<=2)
            ans+=s[i];

        }
        ans+=s[s.length()-1];

        return ans;
    }
};