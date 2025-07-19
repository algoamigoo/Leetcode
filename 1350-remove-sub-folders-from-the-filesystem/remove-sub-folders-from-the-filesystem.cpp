class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        int i = 1, j = 0, n = folder.size();
        while (i < n) {
            if (ans.size() == 0 || ans.back() != folder[j])
                ans.push_back(folder[j]);

            int len = folder[j].length();
            if (folder[i].substr(0, len) == folder[j] &&
                folder[i][len] == '/')
                i++;
            else {
                j = i;
                i++;
            }
        }
        int len = folder[j].length();
        if (folder[n-1].substr(0, len) == folder[j] &&
        folder[n-1][len] == '/')
        {}
        else
        ans.push_back(folder[n-1]);
        return ans;
    }
};