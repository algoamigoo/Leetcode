class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {

        int l=0,h= nums.size();
        int ans=0;
        while(l<h){
            int mid = (l+h)/2;
            if(nums[mid]-mid-1<k)
            l=mid+1;
            else
            h=mid;
        }
        return l+k;
    }
};