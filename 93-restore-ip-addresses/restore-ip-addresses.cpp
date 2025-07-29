class Solution {
public:
    vector<string> ans;
    bool check(string s){
        if(s.length() == 1)
            return true;
        if(s[0] == '0')
            return false;
        if(s.length() == 2)
            return stoi(s) <= 255;
        if(s[0] > '2')
            return false;
        if(s[0] == '2' && s[1] > '5')
            return false;
        if(s[0] == '2' && s[1] == '5' && s[2] > '5')
            return false;
        return true;
    }

    void backtrack(int start, string curr, string& s, int n, int segments) {
        if(segments == 4 && start == n) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if(segments >= 4 || start >= n)
            return;

        for(int i = start; i < n && i < start + 3; i++) {
            string block = s.substr(start, i - start + 1);
            if(check(block)) {
                string temp = curr + block + '.';
                backtrack(i + 1, temp, s, n, segments + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if(n < 4 || n > 12)
            return {};
        string curr = "";
        backtrack(0, curr, s, n, 0);
        return ans;
    }
};