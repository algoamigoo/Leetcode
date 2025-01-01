class Solution {
public:
    //1st Jan 2025
    // happy new year
    // 11:15 am 
    int maxScore(string s) {
        int score=0,curr=0,zero=0,one=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
            one++;
        }

        for(int i=0;i<s.length()-1;i++)
        {   
            if(s[i]=='0')
            zero++;   
            else
            one--;
            curr=zero+one;
            score=max(score,curr);
        }
        return score;
    }
};