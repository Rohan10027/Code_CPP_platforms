class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(), a.end());
        int i = 0, j = m-1;
        int mndiff = INT_MAX;
        while(j < a.size()){
            mndiff = min(mndiff, a[j]-a[i]);
            j++;
            i++;
        }
        return mndiff;
    }
};
