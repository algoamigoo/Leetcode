class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";

        // a^2+b^2 should be maximised
        // a+b is fixed
        // ab is minimized, when they are far so exhaust the numbers by using 9s
        // then then use rest zeros
        int nines = sum/9;
        int rem = sum%9;
        for(int i=1;i<=nines;i++)
        ans+='9';

        if(rem!=0)
        ans+=to_string(rem);

        if(ans.length()>num)
        return "";

        int currlen = ans.length();
        for(int i=1;i<=num-currlen;i++)
        ans+='0';
        return ans;
    }
};