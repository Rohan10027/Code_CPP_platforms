
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345; // Define the modulo constant.
        int n = grid.size(); // Get the number of rows in the grid.
        int m = grid[0].size(); // Get the number of columns in the grid.
        vector<vector<int>> Ans = grid; // Create a result matrix and initialize it with the grid values.

        // Initialize the result matrix elements to 1.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Ans[i][j] = 1;
            }
        }

        long long Mul = 1; // Initialize a variable to keep track of the cumulative product.

        // Calculate the product of elements in the forward direction (left to right, top to bottom).
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (Ans[i][j] *= Mul) %= mod; // Multiply the element with the cumulative product and apply modulo.
                (Mul *= grid[i][j]) %= mod; // Update the cumulative product.
            }
        }

        Mul = 1; // Reset the cumulative product to 1.

        // Calculate the product of elements in the reverse direction (right to left, bottom to top).
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                (Ans[i][j] *= Mul) %= mod; // Multiply the element with the cumulative product and apply modulo.
                (Mul *= grid[i][j]) %= mod; // Update the cumulative product.
            }
        }

        return Ans; // Return the product matrix.
    }
};
