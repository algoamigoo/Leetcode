class Solution {
public:

    string f(int n){
        string s="";
        while (n > 0) {
        s = s + to_string(n % 2);
        n = n / 2;
    }
        reverse(s.begin(),s.end());
        return s;
    }
    int minimizeXor(int num1, int num2) {
        string s1 = f(num2);
        string s2 = f(num1);
        int x = count(s1.begin(), s1.end(), '1');
       
        //cout<<s1<<" "<<s2<<" "<<endl;
        while ((int)s2.length() < 32) 
        s2 = '0' + s2;

        string s3 = "";
        int q=0;
        while(q < s2.length())
        {s3+='0';q++;}


        for(int i=0;i<32;i++){
            if(x>0 && s2[i]=='1')
            {s3[i]='1';x--;}
        }
        cout<<x<<endl;

        for(int i=31;i>=0;i--){
            if(x>0 && s2[i]=='0')
            {s3[i]='1';x--;}
        }

        long long ans=0;
        for(int i=0;i<s3.length();i++){
            if(s3[i]=='1')
            ans+=pow(2,31-i);
        }

        return ans;
    }
};