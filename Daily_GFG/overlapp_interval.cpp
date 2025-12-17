class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>> ans;
      
      int n = arr.size();
      vector<vector<int>> temp(n+1, vector<int>(2, 10000002));
      
      for(int i=0; i<n; i++){
        temp[i][0] = arr[i][0];
        temp[i][1] = arr[i][1];
      }
      
      sort(temp.begin(), temp.end());
      
      int s=temp[0][0], e=temp[0][1];
      
      for(int i=1; i<=n; i++){
        int cur_s=temp[i][0], cur_e=temp[i][1];
        
        if(cur_s > e){
          vector<int> t(2);
          t[0] = s;
          t[1] = e;
          ans.push_back(t);
          
          e = cur_e;
          s = cur_s;
        }else{            // merge
           e = max(e, cur_e); 
           s = min(s, cur_s);    
        }
        
      }
      
      return ans;
    }
};
