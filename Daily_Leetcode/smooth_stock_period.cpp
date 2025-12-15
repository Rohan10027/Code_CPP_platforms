class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int *dp = new int[prices.size()];
        dp[0] = 1;
        long long ans = 1;
        for(int i = 1; i < prices.size(); i ++) {
            if(prices[i] == prices[i - 1] - 1) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
            ans += dp[i];
        }
        return ans;
    }
};
