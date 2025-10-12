class Solution {
public:
    int f1(string& s) {
        int n = s.size(), ans = 1, cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                cnt++;
            else
                cnt = 1;
            ans = max(ans, cnt);
        }
        return ans;
    }

    int f2(string& s, char x, char y) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[0] = -1;
        bool hasX = false, hasY = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == x) {
                sum++;
                hasX = true;
            } else if (s[i] == y) {
                sum--;
                hasY = true;
            } else {
                // unrelated char → reset everything
                mp.clear();
                mp[0] = i;
                sum = 0;
                hasX = hasY = false;
                continue;
            }

            if (hasX && hasY && mp.find(sum) != mp.end())
                ans = max(ans, i - mp[sum]);
            else if (!mp.count(sum))
                mp[sum] = i;
        }

        return ans;
    }

    int f3(string& s) {
        int n = s.size(), ans = 0;
        int ca = 0, cb = 0, cc = 0;
        map<pair<int, int>, int> mp; // (a-b, a-c) -> earliest index
        mp[{0, 0}] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                ca++;
            else if (s[i] == 'b')
                cb++;
            else
                cc++;

            int d1 = ca - cb;
            int d2 = ca - cc;
            pair<int, int> key = {d1, d2};

            if (mp.find(key) != mp.end())
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }
        return ans;
    }

    int longestBalanced(string s) {
        int ans = 0;
        ans = max(ans, f1(s));
        ans = max(ans, f2(s, 'a', 'b'));
        ans = max(ans, f2(s, 'a', 'c'));
        ans = max(ans, f2(s, 'b', 'c'));
        ans = max(ans, f3(s));
        return ans;
    }
};