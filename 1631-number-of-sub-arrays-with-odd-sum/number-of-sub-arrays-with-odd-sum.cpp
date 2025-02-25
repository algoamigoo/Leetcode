class Solution {
public:
    int numOfSubarrays(vector<int>& v) {

        // 1 4 9
        int n=v.size();
        vector<int> pre(n,0);
        pre[0]=v[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+v[i];
        }
        long long ans=0,o=0,e=0,mod=1e9+7;
        for(int i=0;i<n;i++){
            if(pre[i]%2)
            {o++;ans=(ans+e%mod)%mod;
            ans++;}
            else
            {e++;ans=(ans+o%mod)%mod;}
        }


        return ans;

    }
};