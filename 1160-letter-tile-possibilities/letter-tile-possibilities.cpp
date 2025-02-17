#include <unordered_set>
#include <string>
#include <algorithm>

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        int n = tiles.length();
        
        // Sort the tiles to handle duplicates
        sort(tiles.begin(), tiles.end());
        do {
            for (int len = 1; len <= n; ++len) {
                string s = tiles.substr(0, len);
                st.insert(s);
            }
        } while (next_permutation(tiles.begin(), tiles.end()));
        
        return st.size();
    }
};