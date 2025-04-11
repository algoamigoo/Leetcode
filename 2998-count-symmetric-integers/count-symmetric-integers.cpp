class Solution {
public:
    int digi(string s){
        int i=0,sum=0;
        while(i<s.length()){
            sum+=s[i]-'0';
            i++;
        }
        return sum;
    }
    int func(int n){
        int c=0;
        for(int i=1;i<=n;i++){
        string s = to_string(i);
            if(s.length()%2)
            c+=0;
            else{
                string half1 = s.substr(0,s.length()/2);
                string half2 = s.substr(s.length()/2,s.length()/2);
                int sum1 = digi(half1);
                int sum2 = digi(half2);
                if(sum1==sum2)
                c++;
            }
        }
        return c;
    }
    int countSymmetricIntegers(int low, int high) {
        return func(high)-func(low-1);
    }
};