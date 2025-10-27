class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> beams;
        for(int i=0;i<bank.size();i++){
            int curr=0;
            for(int j=0;j<bank[i].length();j++){
                if(bank[i][j]=='1')
                curr++;
            }
            if(curr!=0)
            beams.push_back(curr);
        }
        int ans=0;
        if(beams.size()==0)
        return 0;
        for(int i=0;i<beams.size()-1;i++){
            ans+=beams[i]*beams[i+1];
        }
        return ans;
    }
};