class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=0,curr=0;
        for (int i = 0; i < blocks.length(); i++) {
            for (int j = 0; j < k; j++) {
                if (i + j < blocks.length()) {

                    if (blocks[i + j] == 'B')
                        curr++;
                }
            }
            ans = max(curr, ans);
            curr=0;
        }
        return k-ans;
    }
};