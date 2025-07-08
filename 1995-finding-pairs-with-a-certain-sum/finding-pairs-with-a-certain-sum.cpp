class FindSumPairs {
public:
    unordered_map<int,int> m;
    vector<int> v1,v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1=nums1;
        v2=nums2;
        for(int i=0;i<v2.size();i++)
        m[v2[i]]++;
    }
    void add(int index, int val) {
        m[v2[index]]--;
        v2[index]+=val;
        m[v2[index]]++;
    }
    
    int count(int tot) {
        int c=0;
        for(int i=0;i<v1.size();i++)
        c+=m[tot-v1[i]];

        return c;
    }
};