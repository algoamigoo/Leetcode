class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2) return false;
        int c = 0;
		
        for(int i=0; i<n; i++) {
            if(locked[i] == '0' || s[i] == '(') c++;   
            else c--; 
			
            if(c < 0) return false;
        }
        c = 0;

        for(int i=n-1; i>=0; i--) {
            if(locked[i] == '0' || s[i] == ')') c++;
            else c--;
            if(c < 0) return false;
        }
        
        return true;
    }
};