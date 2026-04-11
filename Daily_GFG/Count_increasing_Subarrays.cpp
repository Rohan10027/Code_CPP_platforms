class Solution {
  public:
    int countIncreasing(vector<int>& arr) {

        int n=arr.size();
        int cnt=0;
        int i=0,j=1;
        
        while(j<n){
            while(j<n && arr[j-1]<arr[j]) j++;
            int t=j-i;
            cnt+=(t*(t-1))/2;
            i=j;
            j++;
        }
        return cnt;
    }
};
