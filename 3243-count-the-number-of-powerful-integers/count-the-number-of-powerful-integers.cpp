class Solution {
public:
    long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
    long long solve(string &str,string & trail, int limit){
        if(str.length()<trail.length()){
            return 0;
        }
        long long c=0;

        string ending = str.substr(str.length()-trail.length());
        int l=str.length()-trail.length();

        for(int i=0;i<l;i++){
            int digit = str[i]-'0';
            if(digit<=limit)
            c+=digit*binpow(limit+1,l-i-1);
            else{
                c+=binpow(limit+1,l-i);
                return c;
            }
        }
        if(ending>=trail){
            c++;
        }
        return c;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string start_str=to_string(start-1);
        string finish_str = to_string(finish);

        return solve(finish_str,s,limit)-solve(start_str,s,limit);      
    }
};