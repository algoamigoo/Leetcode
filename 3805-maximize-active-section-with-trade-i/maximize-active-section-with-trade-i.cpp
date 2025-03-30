class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int c=1;
        vector<pair<char,int>> v;
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
            c++;
            }
            else{
                v.push_back({s[i],c});
                c=1;
            }
        }
        v.push_back({s[n - 1], c});
        
        int m = v.size();

        if(m==1){
            if(v[0].first=='1')
            return v[0].second;
            else
            return 0;
        }
        else if(m==2){
            if(v[0].first=='1')
            return v[0].second;
            else
            return v[1].second;
        }

        int sum=0;
        for(int i=0;i<m-2;i++){
            if(v[i].first=='0' && v[i+1].first=='1' && v[i+2].first=='0')
            sum=max(sum,v[i].second+v[i+2].second);
        }
        for(int i=0;i<m;i++){
            if(v[i].first=='1')
            sum+=v[i].second;
        }
        return sum;
    }
};