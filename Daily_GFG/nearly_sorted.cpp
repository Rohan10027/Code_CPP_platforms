class Solution {
  public:
    virtual void nearlySorted(vector<int> &a, int k){
      priority_queue<int, vector<int>, greater<int>> pq;
      
      int i=0;
      for(auto x: a){
          pq.push(x);
          if(pq.size() > k){
              a[i] = pq.top();
              pq.pop();
              i++;
          }
      }
      
      while(!pq.empty()){
          a[i] = pq.top();
          pq.pop();
          i++;
      }
      
      return;           
    }
};
