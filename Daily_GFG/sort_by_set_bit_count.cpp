class Solution {
  public:
    int countsetbits(int n){
        unsigned int count=0;
        while(n){
            count+=n&1;
            n/=2;
        }
        return count;
    }
    
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        vector<pair<int,int>> v;
        vector<int> ans;
        int n=arr.size();
        for(int i=0;i<n;i++){
            v.push_back({countsetbits(arr[i]),i});
        }
        sort(v.begin(),v.end(),[&](const pair<int,int>&a, const pair<int,int>&b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            else return a.first>b.first;
        });
        for(auto it : v){
            ans.push_back(arr[it.second]);
        }
        return ans;
    }
};
