class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans =0.00001;
    
        int n = points.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    double a = sqrt(pow(points[i][0]-points[j][0],2) +pow(points[i][1]-points[j][1],2));
                    double b = sqrt(pow(points[i][0]-points[k][0],2) +pow(points[i][1]-points[k][1],2));
                    double c = sqrt(pow(points[k][0]-points[j][0],2) +pow(points[k][1]-points[j][1],2));
                    double s = (a+b+c)/2.0;
                    double area = sqrt(s*(s-a)*(s-b)*(s-c));
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};