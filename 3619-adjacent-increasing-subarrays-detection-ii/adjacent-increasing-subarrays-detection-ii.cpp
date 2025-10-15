class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        int curr=1;
        vector<int> v;
        int f=0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i])
            {curr++;f=0;}
            else
                {v.push_back(curr);
                curr=1;f=1;}
        }
        v.push_back(curr);
        //cout<<v.size()<<" ";
        //cout<<endl;
        if(v.size()==1)
        return max(1,v[0]/2);
        
        int mx2=0;
        curr=0;
        for(int i=0;i<v.size()-1;i++){
            cout<<v[i]<<" ";
            curr=min(v[i],v[i+1]);
            mx=max(mx,curr);
            mx2=max(mx2,v[i]);
        }
        mx2=max(mx2,v[v.size()-1]);
        //cout<<endl;
        //cout<<mx<<" "<<mx2<<endl;
        return max(mx,mx2/2);
    }
};