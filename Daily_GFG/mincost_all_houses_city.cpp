class Solution {
  public:
    int find(int d,vector<int> &p){
           if(p[d] == d){
               return d;
           }
           return find(p[d],p);
    }
    int minCost(vector<vector<int>>& houses) {
        //cost of "connecting" i.e. DSU will apply here.
        int cost = 0;
        int n = houses.size();
        vector<int> p(n);
        for(int i = 0;i<n;i++){
            p[i] = i;
        }
        map<pair<int,int>,int> mp;
        for(int i = 0;i<n;i++){
            mp[{houses[i][0],houses[i][1]}] = i;
        }
        vector<int> r(n,0);
        vector<pair<int,pair<int,int>>> v;
        for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int a = houses[i][0];
            int b = houses[i][1];
            int c = houses[j][0];
            int d = houses[j][1];
            int sum = abs(d-b)+abs(c-a);
            v.push_back({sum,{mp[{a,b}],mp[{c,d}]}});
        }
        }
        sort(v.begin(),v.end());
        for(int i = 0;i<v.size();i++){
            int a = v[i].first;
            int b = v[i].second.first;
            int c = v[i].second.second;
            int x = find(b,p);
            int y = find(c,p);
            if(x == y){
              continue;
            }
            else{
                cost += a;
                if(r[x] <= r[y]){
                    p[x] = y;
                    if(r[y] < r[x] + 1){
                       r[y] = r[x] + 1;
                    }
                }
                else{
                    p[y] = x;
                    if(r[x] < r[y] + 1){
                       r[x] = r[y] + 1;
                    }
                }
            }
        }
        return cost;
    }
};
