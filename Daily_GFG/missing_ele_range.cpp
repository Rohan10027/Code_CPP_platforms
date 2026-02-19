class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
             
           int n =arr.size();
        
           vector<int>s(high-low+1,0);
           
           for(int i:arr){
                 
                if(i<low || i>high) continue;
                
                int idx =i-low;
                
                s[idx]=1;
                
           }
           
           vector<int>ans;
           for(int i=0;i<s.size();i++){
                 if(s[i]==0){
                      ans.push_back(low+i);
                 }
           }
           
           return ans;
               
    }
};
