// Include necessary headers
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        // Get dimensions of grid and queries
        int m = grid.size();        // number of rows
        int n = grid[0].size();     // number of columns
        int k = queries.size();     // number of queries
        
        // Step 1: Create a vector of pairs to store queries with their original indices
        // We need to sort queries but keep track of original positions
        vector<pair<int,int>> sortedQueries;
        for(int i = 0; i < k; i++) {
            sortedQueries.push_back({queries[i], i});
        }
        // Sort queries in ascending order to process smaller values first
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // Step 2: Define direction vectors for 4 adjacent cells (down, right, up, left)
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        // Step 3: Initialize result array and visited matrix
        vector<int> ans(k, 0);              // answer array initialized with zeros
        vector<vector<bool>> visited(m, vector<bool>(n, false));  // track visited cells
        
        // Step 4: Use min-heap priority queue to process cells by increasing value
        // Format: {value, {row, col}}
        priority_queue<pair<int, pair<int,int>>, 
                      vector<pair<int, pair<int,int>>>, 
                      greater<>> pq;
        
        // Step 5: Start from top-left corner
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int points = 0;  // count of reachable cells for current query
        
        // Step 6: Process each query in sorted order
        for(auto [queryVal, idx] : sortedQueries) {
            // Process cells until we reach a value >= current query
            while(!pq.empty() && pq.top().first < queryVal) {
                int val = pq.top().first;          // current cell value
                int row = pq.top().second.first;   // current row
                int col = pq.top().second.second;  // current column
                pq.pop();
                
                points++;  // increment points for this new cell
                
                // Check all 4 adjacent cells
                for(auto d : dir) {
                    int newRow = row + d[0];
                    int newCol = col + d[1];
                    
                    // Check if new position is valid and not visited
                    if(newRow >= 0 && newRow < m && 
                       newCol >= 0 && newCol < n && 
                       !visited[newRow][newCol]) {
                        pq.push({grid[newRow][newCol], {newRow, newCol}});
                        visited[newRow][newCol] = true;
                    }
                }
            }
            // Step 7: Assign points to current query
            // If queue is empty but query is larger, all remaining cells are reachable
            ans[idx] = pq.empty() ? points : points;
        }
        
        return ans;
    }
};