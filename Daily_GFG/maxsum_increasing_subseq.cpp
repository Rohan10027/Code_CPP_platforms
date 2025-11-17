class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int res = 0,n = arr.size();
        
        vector<int> dp(n,0);
        
        for(int i=0;i<n;i++){
            int best = 0;
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    best = max(best,dp[j]);
                }
            }
            dp[i] = best+arr[i];
            res= max(res,dp[i]);
        }
        
        return res;
    }
};
