class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
        int c1=1,c2=1,mxc1=1,mxc2=1;

        for(int i=0;i<v.size()-1;i++){
        
        cout<<mxc1<<" "<<i+1<<endl;
        if(v[i+1]<=v[i])
        c1=1;
        else
        c1++;

        
        mxc1=max(mxc1,c1); 
        if(v[i+1]>=v[i])
        c2=1;
        else
        c2++;
               
        mxc2=max(mxc2,c2);
        
    }
    return max(mxc1,mxc2);
    }
};