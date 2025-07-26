class Solution {
public: set<string> res; // Use set to avoid duplicates
    
    void backtrack(string& subset, string& tiles, vector<bool>& used) {
        if (!subset.empty()) {
            res.insert(subset);
        }
        
        for (int i = 0; i < tiles.length(); i++) {
            if (used[i]) continue;
            
            // Skip duplicates: if same character and previous same character not used
            if (i > 0 && tiles[i] == tiles[i-1] && !used[i-1]) continue;
            
            subset.push_back(tiles[i]);
            used[i] = true;
            backtrack(subset, tiles, used);
            subset.pop_back();
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        string subset = "";
        vector<bool> used(tiles.length(), false);
        backtrack(subset, tiles, used);
        return res.size();
    }
};