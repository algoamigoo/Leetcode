class Solution {
public:
    int maxBottlesDrunk(int numBottles, int x) {
        int ans = numBottles;
            while(numBottles>=x){
                numBottles=numBottles-x;
                x++;
                numBottles++;
                ans++;
            }
        return ans;
    }
};
