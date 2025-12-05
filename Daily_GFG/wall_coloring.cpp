class Solution {
  public:
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size(), k = costs[0].size();
        if(k == 1)
        {
            if(n == 1)
                return costs[0][0];
            else
                return -1;
        }
        vector<int> x(k), y(k);
        for (int i = 0; i < n; i++)
        {
            vector<int> curr(k);
            for (int j = 0; j < k; j++)
            {
                int p = (j > 0) ? x[j - 1] : INT_MAX;
                int q = (j + 1 < k) ? y[j + 1] : INT_MAX;
                int mini = min(p, q);
                if (mini == INT_MAX)
                    return -1;
                int cost = mini + costs[i][j];
                curr[j] = cost;
            }
            int mini = INT_MAX;
            for (int j = 0; j < k; j++)
            {
                mini = min(mini, curr[j]);
                x[j] = mini;
            }
            mini = INT_MAX;
            for (int j = k - 1; j >= 0; j--)
            {
                mini = min(mini, curr[j]);
                y[j] = mini;
            }
        }
        int ans = min(x[k - 1], y[0]);
        return ans;
    }
};
