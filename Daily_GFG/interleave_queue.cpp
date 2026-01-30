class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int>f;
        
        int n=q.size()/2;
        
        for(int i=0;i<n;i++){
            f.push(q.front());
            q.pop();
        }
        while(!f.empty()){
            q.push(f.front());
            q.push(q.front());
            f.pop();
            q.pop();
        }
    }
};
