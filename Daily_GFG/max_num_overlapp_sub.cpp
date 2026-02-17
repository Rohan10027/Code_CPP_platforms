class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int maxVal = 0;
        
        for (auto &it : arr) maxVal = max(maxVal, it[1]);
        
        vector<int> diff(maxVal+2, 0);
        
        for (auto &it : arr){
            diff[it[0]]++;
            diff[it[1]+1]--;
        }
        
        int ans = 0;
        
        for (int i = 1; i <= maxVal; i++) diff[i] += diff[i-1];
        
        for (int i = 0; i <= maxVal; i++) ans = max(ans, diff[i]);
        
        return ans;
    }
};
