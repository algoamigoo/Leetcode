class Solution {
public:
    vector<int> getFinalState(vector<int>& v, int k, int m) {
        int n = v.size();
        
        for (int i = 0; i < k; ++i) {
            int mn = *min_element(v.begin(), v.end());
            
            for (int& num : v) {
                if (num == mn) {
                    num *= m;
                    break;
                }
            }
        }
        
        return v;
    }
};