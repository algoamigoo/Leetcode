class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();
        int full = (n/k)*k;
        int rest = full;
        // padding fill chars to rest
        string tail = "";
        for(int i=rest;i<n;i++){
            tail+=s[i];
        }
        int t = tail.size();
        for(int i=1;i<=k-t;i++)
        tail+=fill;

        for(int i=0;i<rest;i++){
            int j=0;
            string t="";
            while(j!=k){
            t+=s[i];
            j++;
            i++;
            }
            i--;
            ans.push_back(t);
        }        
        if(tail.length()>0 && n%k!=0)
        ans.push_back(tail);
        return ans;
    }
};