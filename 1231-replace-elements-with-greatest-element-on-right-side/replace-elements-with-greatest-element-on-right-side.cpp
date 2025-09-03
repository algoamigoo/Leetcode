class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        int mx = 0;
        for (int i = 0; i < n; i++) {

            while (i < j) {
                mx = max(mx, arr[j]);
                j--;
            }
            arr[i]=mx;
            mx=0;
            j=n-1;
        }
        arr[n-1]=-1;
        return arr;
    }
};