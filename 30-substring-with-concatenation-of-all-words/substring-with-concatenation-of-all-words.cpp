class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), totalwords = words.size(), m = words[0].length();
        if (n < totalwords * m) return {};
        
        unordered_map<string, int> wordFreq;
        for (const string& word : words) wordFreq[word]++;
        
        vector<int> result;
        
        for (int i = 0; i < m; i++) {
            int left = i, count = 0;
            unordered_map<string, int> used;
            
            for (int right = i; right + m <= n; right += m) {
                string word = s.substr(right, m);
                if (wordFreq.find(word) != wordFreq.end()) {
                    used[word]++;
                    count++;
                    
                    while (used[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, m);
                        used[leftWord]--;
                        count--;
                        left += m;
                    }
                    
                    if (count == totalwords) result.push_back(left);
                } else {
                    used.clear();
                    count = 0;
                    left = right + m;
                }
            }
        }
        return result;
    }
};
