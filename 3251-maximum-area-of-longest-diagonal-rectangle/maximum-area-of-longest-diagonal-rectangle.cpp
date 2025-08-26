class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int dia=0,area=0;
        for(int i=0;i<n;i++){
            int u = dimensions[i][0];
            int v = dimensions[i][1];

            if(u*u+v*v >dia){
                dia=u*u+v*v;
                area = u*v;
            }
            else if(u*u+v*v == dia){
                area = max(u*v,area);
            }
        }
        return area;
    }
};