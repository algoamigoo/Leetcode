class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> lines;         // Each vector<string> is one line of words
        vector<string> currLine;              // Temporary container for the current line
        int currLen = 0;                      // Total characters (excluding spaces) in current line

        // Step 1: Brute-force pack words greedily
        for (string &word : words) {
            // If adding the next word would exceed maxWidth
            if (currLen + currLine.size() + word.size() > maxWidth) {
                lines.push_back(currLine);    // Store the current line
                currLine.clear();
                currLen = 0;
            }
            currLine.push_back(word);
            currLen += word.size();           // Update total character length
        }
        if (!currLine.empty()) lines.push_back(currLine); // Add the last line

        // Step 2: Justify each line
        vector<string> result;

        for (int idx = 0; idx < lines.size(); ++idx) {
            vector<string>& line = lines[idx];
            int totalChars = 0;
            for (string &w : line) totalChars += w.size(); // Count non-space characters

            int spaces = maxWidth - totalChars;
            int gaps = line.size() - 1;
            string s;

            // If it's the last line or only one word, left-justify
            if (idx == lines.size() - 1 || gaps == 0) {
                s = line[0];
                for (int i = 1; i < line.size(); ++i)
                    s += " " + line[i];
                s += string(maxWidth - s.size(), ' '); // Pad trailing spaces
            } else {
                // Distribute spaces evenly for full justification
                int spacePerGap = spaces / gaps;
                int extra = spaces % gaps;

                for (int i = 0; i < line.size(); ++i) {
                    s += line[i];
                    if (i < gaps) {
                        s += string(spacePerGap + (i < extra ? 1 : 0), ' ');
                    }
                }
            }

            result.push_back(s);
        }

        return result;
    }
};
