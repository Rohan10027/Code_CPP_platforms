class Solution {
  public:
    pair<int,int> solve(int n,unordered_map<int,vector<int>> &adj,unordered_map<int,bool>&vis){
        vis[n] = 1;
        pair<int,int> ans = {0,0};
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto nbr : adj[n]){
            if(!vis[nbr]){
    
               auto s =  solve(nbr,adj,vis);
               pq.push(s.second);
               if(pq.size() > 2) pq.pop();
               
               ans.first = max({ans.first,s.first});
               ans.second = max(ans.second,s.second+1);
            }
        }
        int t= 1;
        int maxi = 0;
        while(pq.size()){
            maxi = max(pq.top(),maxi);
            t+=pq.top();
            pq.pop();
            
        }
        ans.first = max(ans.first,t);
        ans.second = max(ans.second,maxi+1);
        // cout<<n<<" -> "<<ans.first<<" "<<ans.second<<endl;
        return ans;
    }
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>> adj;
        
        for(auto i : edges){
            auto f = i[0];
            auto s = i[1];
            adj[f].push_back(s);
            adj[s].push_back(f);
        }
        unordered_map<int,bool>vis;
        
        return solve(0,adj,vis).first - 1;
        
    }
};

