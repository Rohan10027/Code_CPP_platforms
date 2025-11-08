class Solution {
  public:
    int solve(int i, int j, int k, vector<vector<int>>& mat, vector<vector<vector<int>>>& dp){
        if(i>=mat.size() || j>=mat[0].size() || k<0) return 0;
        
        k -= mat[i][j];
        
        if (k < 0) return 0;
        
        if(i==mat.size()-1 && j==mat[0].size()-1){
            return k==0 ? 1 : 0;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        return dp[i][j][k] = solve(i+1, j, k, mat, dp) +
               solve(i, j+1, k, mat, dp);
    }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        vector<vector<vector<int>>> dp(mat.size()+1, vector<vector<int>>(mat[0].size()+1, vector<int>(k+1,-1)));
        return solve(0,0,k,mat, dp);
    }
};
