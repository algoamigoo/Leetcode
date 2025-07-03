class Solution {
public:
    string func(const string &s){
        string a=s;
        for(char c : s){
            char t = (c-'a'+1)%26+'a';
            a.push_back(t);
        }
        return a;
    }

    char kthCharacter(int k) {
        string s="a";
        int len = s.length();
        while(len<k){
            s=func(s);
            len=s.length();
        }
        return s[k-1];
    }
};