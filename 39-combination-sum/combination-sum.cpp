class Solution {
public:
    int n;
    set<vector<int>> ans;
    void backtrack(int i,vector<int>& candidates,vector<int> temp,int sum,int target){
        if(sum==target)
        ans.insert(temp);
        if(i==n || sum>target)
        return;
        
        //backtrack
        backtrack(i+1,candidates,temp,sum,target);
        temp.push_back(candidates[i]);
        backtrack(i,candidates,temp,sum+candidates[i],target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> temp;
        backtrack(0,candidates,temp,0,target);
        vector<vector<int>> final;
        for(auto it : ans){
            final.push_back(it);
        }
        return final;
    }
};