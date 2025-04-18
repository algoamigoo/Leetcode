class Solution {
public:
    void rec(int i, int n, string& s) {
        if (i == 1) s = "1"; // Initialize for n=1
        if (i == n) return; // Stop at nth term
        
        string temp = "";
        int c = 1;
        for (int j = 1; j < s.length(); j++) {
            if (s[j] == s[j-1]) {
                c++;
            } else {
                temp += to_string(c) + s[j-1];
                c = 1;
            }
        }
        // Handle the last group
        if (!s.empty()) {
            temp += to_string(c) + s[s.length()-1];
        }
        
        s = temp; // Update s with the new term
        rec(i+1, n, s); // Recurse for next term
    }
    
    string countAndSay(int n) {
        if (n < 1) return "";
        string s = "";
        rec(1, n, s);
        return s;
    }
};