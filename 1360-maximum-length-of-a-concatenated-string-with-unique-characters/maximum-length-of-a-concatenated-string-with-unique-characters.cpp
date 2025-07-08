class Solution {
public:
    int n;

    bool check(string s) {
        int m[26] = {0}; // Initialize all to 0
        for (char c : s) {
            if (m[c - 'a']++) return false; // Already exists
        }
        return true;
    }

    int func(int i, vector<string>& arr, string s) {
        if (i == n) return s.size();

        int nottake = func(i + 1, arr, s);

        int take = 0;
        if (check(s + arr[i])) {
            take = func(i + 1, arr, s + arr[i]);
        }

        return max(nottake, take);
    }

    int maxLength(vector<string>& arr) {
        n = arr.size();
        return func(0, arr, "");
    }
};
