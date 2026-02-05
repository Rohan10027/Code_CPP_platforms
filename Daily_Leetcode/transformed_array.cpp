class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
            res[i] = A[((i + A[i]) % n + n) % n];
        
        return res;
    }
};
