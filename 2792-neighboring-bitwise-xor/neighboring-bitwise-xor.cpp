class Solution {
public:
    bool doesValidArrayExist(vector<int>& v) {
        int x = count(v.begin(),v.end(),1);
        
        cout<<x<<endl;
        if(x%2==0)
        return true;

        return false;
    }
};