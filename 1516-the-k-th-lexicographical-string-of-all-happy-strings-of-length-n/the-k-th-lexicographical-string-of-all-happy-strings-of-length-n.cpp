//RJ
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<string> &s, string &curr, int n) {
        if (curr.size() == n) {
            s.push_back(curr);
            return;
        }
        
        for (char c : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != c) {
                curr.push_back(c);
                backtrack(s, curr, n);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> s;
        string curr;
        backtrack(s, curr, n);
        if(k<=s.size())
        return s[k-1];
        
        return "";
    }
};
