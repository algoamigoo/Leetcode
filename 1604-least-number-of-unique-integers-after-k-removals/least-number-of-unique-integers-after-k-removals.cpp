class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> m;
        int n = arr.size(), sum = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // smallest at top
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }
        sum=m.size();
        for (auto& it : m) {
            pq.push({it.second,it.first});
        }

        while (true) {
            int remove = pq.top().first;
            if(remove<=k)
            {pq.pop();
            sum--;
            k=k-remove;}
            else
            break;
        }
        return sum;
    }
};