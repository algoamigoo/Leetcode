class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        
        if (n <= 2 * candidates) {
            vector<int> sorted = costs;
            sort(sorted.begin(), sorted.end());
            long long sum = 0;
            for (int i = 0; i < k; i++) {
                sum += sorted[i];
            }
            return sum;
        }
        
        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;
        
        int left = candidates;
        int right = n - 1 - candidates;
        
        for (int i = 0; i < candidates; i++) {
            leftHeap.push(costs[i]);
            rightHeap.push(costs[n - 1 - i]);
        }
        
        long long totalCost = 0;
        
        while (k > 0) {
            if (!leftHeap.empty() && (rightHeap.empty() || leftHeap.top() <= rightHeap.top())) {
                totalCost += leftHeap.top();
                leftHeap.pop();
                
                if (left <= right) {
                    leftHeap.push(costs[left]);
                    left++;
                }
            }
            else {
                totalCost += rightHeap.top();
                rightHeap.pop();
                
                if (left <= right) {
                    rightHeap.push(costs[right]);
                    right--;
                }
            }
            k--;
        }
        
        return totalCost;
    }
};