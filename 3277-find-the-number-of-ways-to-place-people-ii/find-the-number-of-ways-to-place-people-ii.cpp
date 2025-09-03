class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& v) {

        int n = v.size();

        sort(v.begin(), v.end(), cmp);

        int ans = 0;
         for(int i=0;i<n;i++) {

            int x1=v[i][0],y1=v[i][1];
            long long currmn=-1e9-1;

            for(int j=i+1;j<n;j++) {
                int x2=v[j][0],y2=v[j][1];
                if(y2>y1)
                    continue;
                if(y2>currmn)
                    ans++;
                if(y2>currmn)
                    currmn=y2;
            }
        }
        return ans;
    }
};
