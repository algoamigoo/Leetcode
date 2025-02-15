class Solution {
public:
    bool func(string &s, int target, int idx, int sum) {
        if (idx == s.size()) 
        return sum == target;
        int num = 0;
        for (int j = idx; j < s.size(); j++) {
            num = num * 10 + (s[j] - '0');
            if (sum + num <= target && func(s, target, j + 1, sum + num))
                return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int c = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (func(s, i, 0, 0)) 
                c += i * i;
        }
        return c;
    }
};
