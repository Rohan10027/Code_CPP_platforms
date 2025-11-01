class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>> adj(n);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++) {
            for(int v : adj[i]) {
                indegree[v]++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> schedule;
        int i = 0;
        
        while(!q.empty()) {
            int prereq = q.front();
            q.pop();
            
            schedule.push_back(prereq);
            
            for(auto course : adj[prereq]) {
                indegree[course] -= 1;
                
                if(indegree[course] == 0) q.push(course);
            }
            
        }
  
        if(schedule.size() != n) return {};
        return schedule;
        
    }
};
