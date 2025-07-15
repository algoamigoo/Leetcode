class Solution {
public:
    string processStr(string s) {
        string t="";
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i]))
            t+=s[i];

            if(s[i]=='*' && t.length()>=1)
            t.pop_back();
            if(s[i]=='#')
            t=t+t;
            if(s[i]=='%')
            reverse(t.begin(),t.end());
        }
        return t;
    }
};