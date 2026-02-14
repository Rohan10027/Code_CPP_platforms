class Solution {
  public:
    // int minTime(vector<int>& arr, int k) {
    //     // code here
    //     int n=arr.size();
    //     vector<int> dp(n,0);
        
    // }
    bool isPossible(vector<int>& arr, int k, long long maxTime) {
        int painters = 1;
        long long currentSum = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxTime) return false;
            
            if (currentSum + arr[i] > maxTime) {
                painters++;
                currentSum = arr[i];
                
                if (painters > k) return false;
            } else {
                currentSum += arr[i];
            }
        }
        
        return true;
    }
    
public:
    int minTime(vector<int>& arr, int k) {
        long long left = *max_element(arr.begin(), arr.end());
        long long right = accumulate(arr.begin(), arr.end(), 0LL);
        long long result = right;
        
        // Binary search on the answer
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (isPossible(arr, k, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
};
