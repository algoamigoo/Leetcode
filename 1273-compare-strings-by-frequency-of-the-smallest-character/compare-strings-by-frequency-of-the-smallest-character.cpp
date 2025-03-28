#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> v1, v2, ans;

        // Compute f(W) for each word
        for (auto &it : words) {
            sort(it.begin(), it.end());
            int count = 0;
            for (int j = 0; j < it.size(); j++) {
                if (it[j] == it[0]) count++;
            }
            v1.push_back(count);
        }

        // Compute f(Q) for each query
        for (auto &it : queries) {
            sort(it.begin(), it.end());
            int count = 0;
            for (int j = 0; j < it.size(); j++) {
                if (it[j] == it[0]) count++;
            }
            v2.push_back(count);
        }

        // Compare f(Q) with f(W)
        for (int i = 0; i < v2.size(); i++) {
            int count = 0;
            for (int j = 0; j < v1.size(); j++) {
                if (v2[i] < v1[j]) count++;
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};
