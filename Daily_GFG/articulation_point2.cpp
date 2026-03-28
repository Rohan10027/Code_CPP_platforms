class Solution {
  private:
    int timer = 0;
    
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, 
             vector<int>& low, vector<bool>& isAP) {
        disc[u] = low[u] = timer++;
        int children = 0;
        
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                children++;
                dfs(v, u, adj, disc, low, isAP);
                
                low[u] = min(low[u], low[v]);
                
                if (parent == -1 && children > 1) {
                    isAP[u] = true;
                }
                if (parent != -1 && low[v] >= disc[u]) {
                    isAP[u] = true;
                }
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> disc(V, -1);
        vector<int> low(V);
        vector<bool> isAP(V, false);
        timer = 0;
        
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, -1, adj, disc, low, isAP);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isAP[i]) {
                result.push_back(i);
            }
        }
        
        if (result.empty()) {
            result.push_back(-1);
        }
        
        return result;
    }
};
