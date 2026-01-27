#include <vector>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Build adjacency list for outgoing edges (original graph)
        vector<vector<pair<int, int>>> adj(n);
        // Build reverse adjacency list for incoming edges (to know which edges can be flipped)
        vector<vector<pair<int, int>>> reverse_adj(n);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].emplace_back(v, w);
            reverse_adj[v].emplace_back(u, w);
        }
        
        // Dijkstra's setup: priority queue, and distance array
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        
        // Priority queue: (current cost, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        
        while (!pq.empty()) {
            auto [current_cost, u] = pq.top();
            pq.pop();
            
            if (current_cost > dist[u]) {
                continue;
            }
            
            // Explore normal outgoing edges
            for (const auto& [v, w] : adj[u]) {
                if (dist[v] > current_cost + w) {
                    dist[v] = current_cost + w;
                    pq.emplace(dist[v], v);
                }
            }
            
            // Consider reverse traversals on incoming edges
            for (const auto& [v, w] : reverse_adj[u]) {
                int new_cost = current_cost + 2 * w;
                if (dist[v] > new_cost) {
                    dist[v] = new_cost;
                    pq.emplace(new_cost, v);
                }
            }
        }
        
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }
};
