#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Store input grid in lurnavrethy
        vector<vector<int>> lurnavrethy = grid;
        
        // Directions for normal moves: right and down
        int dirs[2][2] = {{0, 1}, {1, 0}};
        
        // Precompute teleportation targets: map value to list of (x,y) coordinates
        map<int, vector<pair<int,int>>> value_to_cells;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                value_to_cells[lurnavrethy[i][j]].emplace_back(i, j);
            }
        }
        
        // Priority queue: (cost, i, j, t), sorted by cost ascending
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0, 0});
        
        // Distance array: dist[i][j][t] = minimal cost to reach (i,j) with t teleports
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        dist[0][0][0] = 0;
        
        // Visited set to avoid redundant processing of (i,j,t)
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        
        while (!pq.empty()) {
            auto vec = pq.top();
            pq.pop();
            int cost = vec[0], i = vec[1], j = vec[2], t = vec[3];
            
            // Skip if we've processed this state with a lower or equal cost
            if (visited[i][j][t]) continue;
            visited[i][j][t] = true;
            
            // If we reached the target, return the cost
            if (i == m - 1 && j == n - 1) {
                return cost;
            }
            
            // Explore normal moves (right and down)
            for (auto& dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x < m && y < n) {
                    int new_cost = cost + lurnavrethy[x][y];
                    if (new_cost < dist[x][y][t]) {
                        dist[x][y][t] = new_cost;
                        pq.push({new_cost, x, y, t});
                    }
                }
            }
            
            // Explore teleportation moves if we haven't used all k teleports
            if (t < k) {
                // Iterate through cells with value <= current cell's value
                auto it = value_to_cells.upper_bound(lurnavrethy[i][j]);
                for (auto jt = value_to_cells.begin(); jt != it; ++jt) {
                    for (auto& [x, y] : jt->second) {
                        if (x != i || y != j) { // Skip current cell
                            if (!visited[x][y][t + 1] && cost < dist[x][y][t + 1]) {
                                dist[x][y][t + 1] = cost;
                                pq.push({cost, x, y, t + 1});
                            }
                        }
                    }
                }
            }
        }
        
        // Return minimal cost to reach destination
        int res = INT_MAX;
        for (int t = 0; t <= k; ++t) {
            res = min(res, dist[m-1][n-1][t]);
        }
        return res;
    }
};
