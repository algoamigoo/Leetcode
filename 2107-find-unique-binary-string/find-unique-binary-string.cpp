class Solution {
public:
    std::string intToBinary(int num, int n) {
        std::string binary = "";
        while (num > 0) {
            binary = (char)('0' + (num % 2)) + binary;
            num /= 2;
        }
        while (binary.size() < n) {
            binary = '0' + binary;
        }
        return binary;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> v;
        
        for (int i = 0; i < n; i++) {
            int x = stoi(nums[i], nullptr, 2);
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        int y = -1;

        for (int i = 0; i < n; i++) {
            if (v[i] != i) {
                y = i;
                break;
            }
        }

        if (y == -1) y = n;

        return intToBinary(y, n); 
    }
};
