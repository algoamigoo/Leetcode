class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    vector<pair<int, int>> p;
    int n = profits.size();

    for(int i = 0; i < n; i++) {
        p.push_back({capital[i], profits[i]});
    }

    sort(p.begin(), p.end()); 

    priority_queue<int> q;
    int i = 0;
    int sum = w;
    while(k--) {
        while(i < n && p[i].first <= sum) {
            q.push(p[i].second);
            i++;
        }

        if(q.empty()) break;

        sum += q.top();
        q.pop();
    }

    return sum;
}

};