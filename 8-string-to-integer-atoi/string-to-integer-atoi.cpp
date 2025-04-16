class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long result = 0; // Use long to handle overflow during computation
        int sign = 1;    // Default to positive
        
        // Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Process digits
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Check for overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }
        
        return result * sign;
    }
};