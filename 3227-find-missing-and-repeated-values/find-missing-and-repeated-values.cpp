class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        set<int> s;
        int n=grid.size();
        int repeat=0;
        
        vector<int> v,ans;
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                s.insert(grid[i][j]);
                v.push_back(grid[i][j]);
            }
        }
        for(int i=1;i<=n*n;i++){
            if(s.find(i)==s.end())
            ans.push_back(i);
        }
        v.push_back(ans[0]);
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

        cout<<endl;
         for (int i = 0; i < v.size()-1; i++) {
        repeat = repeat ^ (i + 1) ^ v[i];
    }
    repeat = repeat ^ v[v.size() - 1];   
    cout<<repeat;
    ans.push_back(repeat);
    swap(ans[0],ans[1]);
    return ans;
    }
};