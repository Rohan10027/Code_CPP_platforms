class Solution {
  public:
    int maxSubarraySum(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), ans = 0;
        for(int i = 0, x = 0; i < n; i++) {
            x += arr[i];
            if(i - k >= 0) x -= arr[i - k];
            ans = max(ans, x);
        }
        return ans;
        
    }
};
