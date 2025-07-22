class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        for (auto it : tasks)
            m[it]++;

        priority_queue<int> pq1;

        for (auto it : m)
            pq1.push(it.second);

        int c = 0;

        while (!pq1.empty()) {
            vector<int> temp;
            int cycle = n + 1;

            while (cycle-- && !pq1.empty()) {
                int freq = pq1.top();
                pq1.pop();
                if (freq - 1 > 0)
                    temp.push_back(freq - 1);
                c++;
            }

            for (int f : temp)
                pq1.push(f);

            if (pq1.empty())
                break;
            c += cycle + 1;
        }

        return c;
    }
};
