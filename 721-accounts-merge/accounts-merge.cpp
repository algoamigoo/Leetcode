class Solution {
public:
    vector<int> rank, parent;

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // map email -> account index
        unordered_map<string, int> emailToAcc;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAcc.count(email)) {
                    Union(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }

        // group emails by root
        unordered_map<int, vector<string>> merged;
        for (auto &p : emailToAcc) {
            string email = p.first;
            int root = find(p.second);
            merged[root].push_back(email);
        }

        // build final answer
        vector<vector<string>> ans;
        for (auto &it : merged) {
            int root = it.first;
            vector<string> &emails = it.second;

            sort(emails.begin(), emails.end());
            vector<string> mergedAcc;
            mergedAcc.push_back(accounts[root][0]);
            for (string &email : emails) {
                mergedAcc.push_back(email);
            }

            ans.push_back(mergedAcc);
        }

        return ans;
    }
};
