class Solution {
  public:
    // vector<string> findExpr(string &s, int target) {
    //     // code here
        
    // }
    void solve(int val, int prev, int target, string &num, string output, int idx, vector<string>&ans){
        if(idx >= num.size()){
            if(val == target){
                ans.push_back(output);
            }
            return;
        }
        string temp = "";
        int curr_val = 0;
        for(int i=idx; i<num.size(); i++){
            temp += num[i];
            curr_val = curr_val*10 + (num[i] - '0');
            if(idx == 0){
                solve(curr_val, curr_val, target, num, temp, i+1, ans);
            }
            else{
                solve(val+curr_val, curr_val, target, num, output+"+"+temp, i+1, ans);
                solve(val-curr_val, -1*curr_val, target, num, output+"-"+temp, i+1, ans);
                solve(val-prev+prev*curr_val, prev*curr_val, target, num, output+"*"+temp, i+1, ans);
            }
            if(num[idx]=='0') break;
        }
    }
public:
    vector<string> findExpr(string &num, int target) {
        vector<string>ans;
        string output;
        int idx = 0;
        int val = 0;
        int prev = 0;
        solve(val, prev, target, num, output, idx, ans);
        return ans;
    }
};
