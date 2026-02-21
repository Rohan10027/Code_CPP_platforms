class Solution {
  public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        
        sort(c.begin(), c.end());
        
        int l = 0, r = n, ans = -1;
        
        while(l <= r) {
            int mid = (l + r) / 2;
            if(c[n-mid] >= mid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return ans;
    }
};
