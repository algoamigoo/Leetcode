class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> m;
            for(int j=i;j<s.length();j++){
                m[s[j]]++;
                int prev=-1,curr=1;
                for(auto it=m.begin();it!=m.end();it++){
                    if(prev==-1) prev=it->second;
                    else if(it->second!=prev){curr=0;break;}
                }
                if(curr) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
