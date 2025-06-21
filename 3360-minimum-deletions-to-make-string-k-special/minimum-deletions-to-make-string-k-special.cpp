class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> m;
        // store freq and sort them

        for(auto it : word)
            m[it]++;
        
        vector<int> v;
        v.push_back(0);
        for(auto it : m)
            v.push_back(it.second);

        sort(v.begin(),v.end());
        int n = v.size(),i=0;
        // now que becomes min no of ops such 
        //that diff b/w any 2 elements is <=k

        // 1 2 3 5

        // and size of vector is upto 26.

        int ans=INT_MAX,sum=0,temp=0;
        // sum upto a particular index say i, remove them, and then calc (v[j]-v[i+1]-k), if positive add
        // and take min of this thing

        for(int i=0;i<n;i++){
            temp=0;
            // delete all before i
            for(int j=0;j<i;j++)
                temp+=v[j];
            // adjust all after i
            for(int j=i+1;j<n;j++){
                int t = v[j]-v[i]-k;
                if(t>0)
                    temp+=t;
            }
            ans=min(temp,ans);
        }

        return ans;
    }
};
