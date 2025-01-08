class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(words[i].size() <= words[j].size()) {
                    string prefix = words[j].substr(0, words[i].size());
                    string suffix = words[j].substr(words[j].size() - words[i].size());
                    
                    if(prefix == words[i] && suffix == words[i]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};