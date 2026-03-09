class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1'000'000'007;

        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0)); // i 0s + j 1s ending with 0
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0)); // i 0s + j 1s ending with 1

        // Base cases: only zeros or only ones => only one string if len <= min(limit, zero/one)
        for (int i = 1; i <= min(zero, limit); ++i) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp1[0][j] = 1;

        // DP iterations
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                for (int k = 1; k <= min(limit, i); ++k)
                    dp0[i][j] = (dp0[i][j] + dp1[i - k][j]) % mod;
                for (int k = 1; k <= min(limit, j); ++k)
                    dp1[i][j] = (dp1[i][j] + dp0[i][j - k]) % mod;
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};
