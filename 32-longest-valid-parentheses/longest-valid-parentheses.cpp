class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        s.push(-1);
        int maxLen = 0;
        int n = str.length();
        
        for(int i = 0; i < n; i++) {
            if(str[i] == '(') {
                s.push(i);
            } else {
                s.pop();
                if(s.empty()) {
                    s.push(i);
                } else {
                    maxLen = max(maxLen, i - s.top());
                }
            }
        }
        return maxLen;
    }
};