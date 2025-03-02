class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int m = minutesToTest/minutesToDie+1;
        int pig = ceil(log2(buckets)/log2(m));

        return pig;
    }
};