class Solution {
public:
    // Helper function to check if we can make m bouquets in `days`
    bool canMakeBouquets(vector<int>& bloomDay, int days, int m, int k) {
        int bouquets = 0, flowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // Reset if flowers are not consecutive
            }
            if (bouquets >= m) return true;
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size(); // Use long long to prevent overflow
        if ((long long)m * k > n) return -1; // Check using 64-bit integers

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate mid
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                answer = mid;  // Update answer
                high = mid - 1; // Try for fewer days
            } else {
                low = mid + 1; // Increase days
            }
        }

        return answer;
    }
};
