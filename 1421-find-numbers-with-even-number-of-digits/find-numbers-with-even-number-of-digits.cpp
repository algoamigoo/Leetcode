class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int c=0;
        for(auto it : nums){
            string s = to_string(it);
            if(s.size()%2==0)
            c++;
        }
        return c;
    }
};