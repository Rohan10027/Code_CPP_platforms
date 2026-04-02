class Solution {
  public:
    int countWays(int n, int k) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return k;
    if (n == 2) return k * 1LL * k;   // Use long long to avoid overflow during multiplication
    
    // Variables to store previous two results (Space optimized - O(1) space)
    long long prev2 = k;           // dp[1]
    long long prev1 = k * 1LL * k; // dp[2]
    
    for(int i = 3; i <= n; i++) {
        long long current = (k - 1LL) * (prev1 + prev2);
        prev2 = prev1;
        prev1 = current;
    }
    
    return prev1;
}
};
