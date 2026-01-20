class Solution {
public:
        vector<int> minBitwiseArray(vector<int>& A) {
        vector<int> res;
        for (int a : A) {
            if (a % 2 == 0) {
                res.push_back(-1);
            } else {
                res.push_back(a - ((a + 1) & (-a - 1)) / 2);
            }
        }
        return res;
    }
};
