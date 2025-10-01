class Solution {
  public:
    void recur(int n,int k,vector<int>& curr,vector<vector<int>>& ans){
        if(k==0){
            if(n==0){
                ans.push_back(curr);
            }
            return;
        }
        for(int i=curr.empty()?1:curr.back()+1;i<10;i++){
            if(n>=i) {
                curr.push_back(i);
                recur(n-i,k-1,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        recur(n,k,curr,ans);
        return ans;
    }
};
