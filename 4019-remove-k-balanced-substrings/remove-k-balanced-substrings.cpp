class Solution {
public:
    string removeSubstring(string s, int k) {
        int n = s.length();
        vector<int> freq;
        int count = 1;

        // Group consecutive '(' or ')'
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && s[i] == s[i + 1]) {
                count++;
            } else {
                if (s[i] == '(') freq.push_back(count);
                else              freq.push_back(-count);
                count = 1;
            }
        }

        // Debug: initial groups
        for (int f : freq) cout << f << " ";
        cout << endl;

        bool changed = true;
        while (changed) {
            changed = false;
            // One cancellation pass (remove as many k-blocks as possible between adjacent + / -)
            for (int i = 0; i + 1 < (int)freq.size(); ++i) {
                if (freq[i] > 0 && freq[i + 1] < 0) {
                    int left = freq[i];
                    int right = -freq[i + 1];
                    int pairs = min(left / k, right / k);
                    if (pairs > 0) {
                        freq[i] -= pairs * k;
                        freq[i + 1] += pairs * k; // adding because freq[i+1] is negative
                        changed = true;
                    }
                }
            }

            if (changed) {
                // Remove zeros and merge adjacent same-sign groups
                vector<int> compressed;
                for (int f : freq) {
                    if (f == 0) continue;
                    if (!compressed.empty() &&
                        ((compressed.back() > 0 && f > 0) || (compressed.back() < 0 && f < 0))) {
                        compressed.back() += f; // merge same sign
                    } else {
                        compressed.push_back(f);
                    }
                }
                freq.swap(compressed);

                // Debug: print compressed groups (no zeros)
                for (int f : freq) cout << f << " ";
                cout << endl;
            }
        }

        // Reconstruct string from final freq
        string ans = "";
        for (int f : freq) {
            if (f > 0) ans += string(f, '(');
            else if (f < 0) ans += string(-f, ')');
        }
        return ans;
    }
};
