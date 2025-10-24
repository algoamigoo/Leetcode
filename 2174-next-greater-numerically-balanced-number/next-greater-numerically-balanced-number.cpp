class Solution {
public:
    bool check(int n)
    {
        int nums[7]={0};
        while(n!=0)
        {
            if(n%10==0 || n%10>6) return false;
            nums[n%10]++;
            n=n/10;
        }
        for(int i=1;i<=6;i++)
        {
            if(nums[i]!=0 && nums[i]!=i) return false;
        }
        return true;
    }
    
    int nextBeautifulNumber(int n) {
    n++;
    while(1)
    {
        if(check(n)) return n;
        n++;
    }
    return 0;
    }
};