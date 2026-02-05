class Solution {
  public:
    virtual int maxOnes(vector<int>& arr, int k) {
      int maxi=0, c0=0, i=0, j=0;
      
      int n=arr.size();
      
      for(j=0; j<n; j++){
        if(arr[j]==0) c0++;
        while(c0>k){
          if(arr[i]==0) c0--;
          i++;
        }
        
        maxi = max(maxi, j-i+1);
      }
      
      return maxi;
    }
};
