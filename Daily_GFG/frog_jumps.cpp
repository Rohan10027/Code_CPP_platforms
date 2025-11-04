class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n=arr.size();
        pair<int,int> a={arr[0],0},b=a;
        for(int i=1;i<n;i++) {
            int c=min(a.second+abs(a.first-arr[i]),b.second+abs(b.first-arr[i]));
            b=a;
            a={arr[i],c};
        }
        return a.second;
    }
};
