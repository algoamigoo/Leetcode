class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int m = potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int l = 0;
            int r = potions.size();
            int curr=0;
            while(l<r){
                int mid = l+(r-l)/2;
                long long thiss = 1LL*potions[mid]*spells[i];
                if(thiss>=success){
                    curr=m-mid;
                    r=mid;
                }
                else{
                    l = mid+1;
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};