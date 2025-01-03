class Solution {
public:
    bool bs(vector<int>& piles, int k, int h) {
        int hrs = 0;
        for (int pile : piles) {
            hrs += (pile + k - 1) / k;
            if (hrs > h) 
            return false;
        }
        return true;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            if (bs(piles, mid, h)) {
                ans = mid; 
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
