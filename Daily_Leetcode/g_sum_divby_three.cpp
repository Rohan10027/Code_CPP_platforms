class Solution {
public:
        int maxSumDivThree(vector<int>& A) {
        vector<int> dp(3);
        for (int a : A)
            for (int i : vector<int>(dp))
                dp[(i + a) % 3] = max(dp[(i + a) % 3], i + a);
        return dp[0];
    }
};
