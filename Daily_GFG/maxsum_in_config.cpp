class Solution {
  public:
    int maxSum(vector<int>& arr) {
        int n = arr.size();
        
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
       
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += i * arr[i];
        }
        
        int maxSum = currentSum;
        for (int i = 0; i < n - 1; i++) {
            int firstElement = arr[i];
            currentSum = currentSum + firstElement * n - totalSum;
            
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};
