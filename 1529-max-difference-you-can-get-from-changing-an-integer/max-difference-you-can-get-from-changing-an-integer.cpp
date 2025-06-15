class Solution {
public:int maxDiff(int num) {
    string s = to_string(num);
    string a = s, b = s;
    int len = s.length();

    // Maximize a: Replace first non-9 digit with 9
    char digit_to_max = '9';
    for (int i = 0; i < len; i++) {
        if (s[i] != '9') {
            digit_to_max = s[i];
            break;
        }
    }
    for (int i = 0; i < len; i++) {
        if (a[i] == digit_to_max) a[i] = '9';
    }

    // Minimize b: Replace first digit with 1, or first non-1, non-0 digit with 0
    if (b[0] != '1') {
        char first_digit = b[0];
        for (int i = 0; i < len; i++) {
            if (b[i] == first_digit) b[i] = '1';
        }
    } else {
        char digit_to_min = '0';
        for (int i = 1; i < len; i++) {
            if (b[i] != '1' && b[i] != '0') {
                digit_to_min = b[i];
                break;
            }
        }
        for (int i = 0; i < len; i++) {
            if (b[i] == digit_to_min) b[i] = '0';
        }
    }

    return stoi(a) - stoi(b);
}
};