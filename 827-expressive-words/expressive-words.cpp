class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        // problem statement
        // we have to find the no of words form the given words which can
        // be made stretchy in order to form given string

        // condition is i have to extend so that size is 3 char or more for
        // each letter that is stretched

         int i, j, curr, count = 0;
        for (int k = 0; k < words.size(); k++) {
            i = 0;
            j = 0;
            curr = 1;
            int f = 0;
            
            while (j < words[k].length() && i < s.length() && f == 0) {
                curr = 1;
                while (i + 1 < s.length() && s[i] == s[i + 1]) {
                    curr++;
                    i++;
                }
                
                if (words[k][j] == s[i]) {
                    int curr2 = 1;
                    while (j + 1 < words[k].length() && words[k][j] == words[k][j + 1]) {
                        curr2++;
                        j++;
                    }
                    
                    if (curr >= 3) {
                        if (curr2 > curr)
                            f = 1;
                    } else {
                        cout << words[k][j] << " " << curr2 << " " << curr << endl;
                        if (curr != curr2)
                            f = 1;
                    }
                } else {
                    f = 1;
                }
                
                i++;
                j++;
            }
            
            if (f == 0 && i == s.length() && j == words[k].length()) {
                count++;
            }
        }
        return count;
    }
};