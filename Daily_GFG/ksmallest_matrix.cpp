class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        vector<int>v;
        for(auto &row : mat){
            for(int x:row){
                v.push_back(x);
            }
        }
        sort(v.begin(), v.end());
        return v[k-1];
    }
};
