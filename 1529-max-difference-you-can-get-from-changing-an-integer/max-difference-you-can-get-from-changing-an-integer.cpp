class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s;
        string b = s;
        int len = s.length();
        // for maximising a

        // step 1 extracting first non 9 digit from string
        char p = '9';
        for (int i = 0; i < len; i++) {
            if (s[i] != '9') {
                p = s[i];
                break;
            }
        }
        // step 2 replacing all the p with 9

        for (int i = 0; i < len; i++) {
            if (a[i] == p)
                a[i] = '9';
        }

        // for minimising b
        if (b[0] != '1') { // case when b isnt 1
            char c = b[0];
            for (int i = 0; i < len; i++) {
                if (b[i] == c)
                    b[i] = '1';
            }
        } else { // case to ensure it remains non zero and minimsed
            char c = '1';
            for (int i = 0; i < len; i++) {
                if (b[i] != '1' && b[i]!='0') {
                    c = b[i];
                    break;
                }
            }

            for (int i = 0; i < len; i++) {
                if (b[i] == c && c == '1')
                    b[i] = '1';
                else if (b[i] == c && c != '1')
                    b[i] = '0';
            }
        }
        int x = stoi(a);
        int y = stoi(b);

        return x - y;
    }
};