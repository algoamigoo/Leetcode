class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int m = part.length();

        for (char c : s) {
            ans.push_back(c);
            if (ans.size() >= m && ans.substr(ans.size() - m) == part) {
                ans.erase(ans.end() - m, ans.end());
            }
        }
        return ans;
    }
};
