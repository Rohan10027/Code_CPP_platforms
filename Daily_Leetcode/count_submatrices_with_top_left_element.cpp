#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Calculate the prefix sum matrix
        vector<vector<int>> prefix_sum(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                prefix_sum[i][j] = grid[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            }
        }

        // Iterate over all possible top-left corners of submatrices
        for (int i = 0; i < 1; ++i) {
            for (int j = 0; j < 1; ++j) {
                // Use sliding window to compute the sum of each submatrix efficiently
                for (int p = i; p < rows; ++p) {
                    for (int q = j; q < cols; ++q) {
                        int sum = prefix_sum[p + 1][q + 1] - prefix_sum[i][q + 1] - prefix_sum[p + 1][j] + prefix_sum[i][j];
                        if (sum <= k) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};
