class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        // 2 words should differ at max
        vector<bool> v(queries.size(),false);
        vector<string> c;
        for(int i=0;i<queries.size();i++){
            for(int j=0;j<dictionary.size();j++){
                if(queries[i].length()==dictionary[j].length()){
                    int t=0;
                    for(int k=0;k<queries[i].length();k++){
                        if(queries[i][k]!=dictionary[j][k])
                        t++;
                    }
                    if(t<=2 && v[i]==false){
                    v[i]=true;
                    c.push_back(queries[i]);
                    }
                }
            }
        }
        return c;
    }
};