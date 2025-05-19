class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, n = words.size();
        
        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;
            
            // Try to fit as many words in this line as possible
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }
            
            int gaps = j - i - 1;
            string line = "";
            
            // Last line or only one word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalChars = 0;
                for (int k = i; k < j; ++k) totalChars += words[k].size();
                int spaces = maxWidth - totalChars;
                int spaceBetween = spaces / gaps;
                int extra = spaces % gaps;
                
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(spaceBetween + (k - i < extra ? 1 : 0), ' ');
                    }
                }
            }
            
            res.push_back(line);
            i = j;
        }
        
        return res;
    }
};
