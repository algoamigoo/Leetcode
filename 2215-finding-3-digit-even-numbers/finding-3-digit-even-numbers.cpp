class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int>result;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && k!=i){
                        int a = digits[i];
                        int b = digits[j];
                        int c = digits[k];
                        if(a==0 || c%2!=0) continue;
                        int num = a * 100 + b * 10 + c;
                        result.insert(num);
                    }
                    
                }
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};