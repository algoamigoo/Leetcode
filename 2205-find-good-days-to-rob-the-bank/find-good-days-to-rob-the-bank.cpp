class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> nonIncrease(n, 0);
        vector<int> nonDecrease(n, 0);

        for (int i = 1; i < n; ++i) {
            if (security[i] <= security[i - 1]) {
                nonIncrease[i] = nonIncrease[i - 1] + 1;
            } else {
                nonIncrease[i] = 0;
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1]) {
                nonDecrease[i] = nonDecrease[i + 1] + 1;
            } else {
                nonDecrease[i] = 0;
            }
        }

        vector<int> result;
        for (int i = time; i < n - time; ++i) {
            if (nonIncrease[i] >= time && nonDecrease[i] >= time) {
                result.push_back(i);
            }
        }

        return result;
    }
};
