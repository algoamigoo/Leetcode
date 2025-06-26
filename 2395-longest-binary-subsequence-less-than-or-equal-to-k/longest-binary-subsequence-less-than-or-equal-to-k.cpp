class Solution {
public:
    int longestSubsequence(string s, int k) {
        reverse(s.begin(),s.end());
        int sum=0,i=-1,n=s.length();
        int c=0;
        while(i<n && sum<=k){
            i++;
            if(s[i]=='1' && sum+pow(2,i)<=k)
            {sum+=pow(2,i);
            c++;}
            else if(s[i]=='0')
            c++;
        }
        return c;
    }
};