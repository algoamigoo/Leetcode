class Solution {
public:
   int GCD(int a, int b){
    while(b != 0 ){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
   }
    bool canMeasureWater(int a, int b, int t) {
        int z = gcd(a,b);
        if(a + b < t) return false;
        if(t==a || t==b || t==a+b)
        return true;
        
        if(t%z==0)
        return true;
        return false;
    }
};