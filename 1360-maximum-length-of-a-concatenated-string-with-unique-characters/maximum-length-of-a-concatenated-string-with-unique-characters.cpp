class Solution {
public:
    int n;
    bool check(string s){
        int m[26]={0};
        for(int i=0;i<s.length();i++){
            if(m[s[i]-'a']!=0)
            return false;
            m[s[i]-'a']++;
        }
        return true;
    }
    int func(int i,vector<string>& arr,string s){
        if(i==n)
        return s.size();

        int nottake = func(i+1,arr,s);
        int take=0;
        if(check(s+arr[i])){
            take = func(i+1,arr,s+arr[i]);
        }
        return max(take,nottake);
    }
    int maxLength(vector<string>& arr) {
        n = arr.size();
        string s ="";
        int ans = func(0,arr,s);
        return ans;
    }
};