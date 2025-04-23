class Solution {
public:
    int sumofdigits(int n){
        int c=0;
        while(n>0){
            c+=n%10;
            n=n/10;
        }
        return c;
    }
    int countLargestGroup(int n) {
        map<int,int> m;
        int mx=0;
        for(int i=1;i<=n;i++){
            int x = sumofdigits(i);
            m[x]++;
        }
        for(auto it : m)
        mx=max(mx,it.second);
        int c=0;
        for(auto it : m)
        {
            if(it.second == mx)
            c++;
        }
        return c;
    }
};