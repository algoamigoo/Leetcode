class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                adj[stop].push_back(i);
            }
        }
        queue<pair<int, int>> q;
        unordered_set<int> visRoutes;
        unordered_set<int> visStops;

        for (int route : adj[source]) {
            q.push({route, 1});
            visRoutes.insert(route);
        }
        visStops.insert(source);

        while (!q.empty()) {
            int currroute = q.front().first;
            int dis = q.front().second;
            q.pop();
            for (int stop : routes[currroute]) {
                if (stop == target) {
                    return dis;
                }

                if (visStops.find(stop) == visStops.end()) {
                    visStops.insert(stop);
                    for (int nextRoute : adj[stop]) {
                        if (visRoutes.find(nextRoute) == visRoutes.end()) {
                            visRoutes.insert(nextRoute);
                            q.push({nextRoute, dis + 1});
                        }
                    }
                }
            }
        }

        return -1;
    }
};