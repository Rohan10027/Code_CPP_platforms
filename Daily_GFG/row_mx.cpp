// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int maxi = INT_MIN;
        int maxirow = INT_MIN;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<m;j++){
                if(arr[i][j] == 1){
                    cnt++;
                }
            }
            
            if(cnt > maxi){
                maxi = cnt;
                maxirow = i;
            }
        }
        return maxirow;
    }
};
