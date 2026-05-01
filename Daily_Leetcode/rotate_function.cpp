class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long sum = 0;
        long F = 0;

        // Initial F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }

        long ans = F;

        // Compute F(k) using formula
        for (int k = 1; k < n; k++) {
            F = F + sum - n * nums[n - k];
            ans = max(ans, F);
        }

        return ans;
    }
};
