class Solution {
  public:
    vector<string> pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void recur(vector<int>& arr,int n,int idx,string& curr,vector<string>& ans){
        if(idx==n) {
            ans.push_back(curr);
            return;
        }
        if(arr[idx]<2) {     // very imp to avoid WA
            recur(arr,n,idx+1,curr,ans);
            return;
        }
        for(auto ch:pad[arr[idx]]){
            curr+=ch;
            recur(arr,n,idx+1,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> ans;
        int n=arr.size();
        string curr="";
        recur(arr,n,0,curr,ans);
        return ans;
    }
};
