class Solution {
  public:
    int orangesRot(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
    
        if (freshCount == 0) return 0;
        
        int minutes = 0;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
 
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
            
                for (auto& dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; 
                        q.push({nr, nc}); 
                        freshCount--;     
                    }
                }
            }
            minutes++;
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};
