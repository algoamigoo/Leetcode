#include <bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) 
    {
        int n=s.length();
        stack<char> st;
        st.push(' ');
        for(int i=0;i<n;i++){
        if(s[i]==' ' && st.top()==' ')
        continue;
        else
        st.push(s[i]);
        }
        string ans="";
        string curr="";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            if(c==' '){
            reverse(curr.begin(),curr.end());
            ans+=curr+" ";
            curr="";
            }
            else
            curr+=c;
        }
        ans+=curr;
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        if(ans.back()==' ')
        ans.pop_back();
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};