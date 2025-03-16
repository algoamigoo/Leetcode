class Solution {
public:
    bool func(long long x,vector<int>&ranks,int cars){
        long long curr = 0;
        for(int i=0;i<ranks.size();i++){
            curr+=sqrt(1.0*x/ranks[i]);
        }
        if(curr>=cars)
        return true;
        
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        long long l=0,r=1e15,ans=0;
        while(l<r){
            long long mid=(l+r)/2;
            if(func(mid,ranks,cars)){
                ans=mid;
                r=mid;
            }
            else
            l=mid+1; 
        }
        return ans;

    }
};