class Solution {
public:
    long long minimumDifference(vector<int>& v) {
        int n = v.size()/3;
        priority_queue<long long> mn;
        priority_queue<long long, vector<long long>, greater<long long>> mx;
        vector<long long> left;
        long long curr = 0;
        for(int i = 0; i < 2*n; i++) {
            mn.push(v[i]);
            curr += v[i];
            if(mn.size() > n) {
                curr -= mn.top();
                mn.pop();
            }
            if(mn.size() == n) {
                left.push_back(curr);
            }
        }
        vector<long long> right;
        curr = 0;
        for(int i = 3*n-1; i >= n; i--) {
            mx.push(v[i]);
            curr += v[i];
            if(mx.size() > n) {
                curr -= mx.top();
                mx.pop();
            }
            if(mx.size() == n) {
                right.push_back(curr);
            }
        }
        reverse(right.begin(), right.end());
        long long ans = LLONG_MAX;
        for(int i = 0; i < left.size(); i++) {
            ans = min(ans, left[i] - right[i]);
        }
        for(int i = 0; i < left.size(); i++)
            cout << left[i] << " ";
        cout << endl;
        for(int i = 0; i < right.size(); i++)
            cout << right[i] << " ";
        cout << endl;

        return ans;
    }
};