class Solution {
    class DSU {
        vector<int> parent;
        vector<int> size;
    public:
        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }
        
        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                if (size[root_i] < size[root_j])
                    swap(root_i, root_j);
                parent[root_j] = root_i;
                size[root_i] += size[root_j];
                return true;
            }
            return false;
        }
    };

    bool check(long long X, int n, const vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int comps = n;
        
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < X) return false;
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= X) {
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        if (comps - 1 > k) return false;
        
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < X && 2LL * e[2] >= X) {
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        return comps == 1;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU init_dsu(n);
        long long max_must_s = 2e9; 
        
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (!init_dsu.unite(e[0], e[1])) {
                    return -1;
                }
                max_must_s = min(max_must_s, (long long)e[2]);
            }
        }
        
        DSU full_dsu(n);
        int full_comps = n;
        for (const auto& e : edges) {
            if (full_dsu.unite(e[0], e[1])) full_comps--;
        }
        if (full_comps > 1) return -1;
        
        long long low = 1, high = min((long long)2e5, max_must_s);
        long long ans = -1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
