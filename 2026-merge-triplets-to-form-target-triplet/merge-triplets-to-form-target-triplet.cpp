class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<int> good;

        for (const auto& t : triplets) {

            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }
            
            for (int i = 0; i < 3; ++i) {
                if (t[i] == target[i]) {
                    good.insert(i);
                }
            }
        }
        
        return good.size() == 3;
    }
};