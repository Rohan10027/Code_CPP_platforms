class Solution {
public:
        int minNumberOperations(vector<int>& A) {
        int res = A[0];
        for (int i = 1; i < A.size(); ++i)
            res += max(A[i] - A[i - 1], 0);
        return res;
    }
};
