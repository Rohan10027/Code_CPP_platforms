// class Solution {
// public:
//     long long maximumScore(vector<vector<int>>& grid) {
        
//     }
// };



#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        long long maxScore = 0;

        // Iterate over each column
        for (int j = 0; j < n; ++j) {
            // Create a copy of the original grid to simulate the operations
            vector<vector<int>> tempGrid = grid;

            // Iterate over each possible row in the column to start coloring black
            for (int i = 0; i < n; ++i) {
                // Color the cells from row 0 to row i in column j black
                for (int k = 0; k <= i; ++k) {
                    tempGrid[k][j] = -1;  // Representing black cell by -1
                }

                // Calculate the score with the current configuration
                long long currentScore = calculateScore(tempGrid);
                maxScore = max(maxScore, currentScore);

                // Restore the grid for the next iteration
                tempGrid = grid;
            }
        }

        return maxScore;
    }

private:
    long long calculateScore(const vector<vector<int>>& grid) {
        int n = grid.size();
        long long score = 0;

        // Iterate over each cell to calculate the score
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != -1) {  // If the cell is white
                    // Check if it has a horizontally adjacent black cell
                    if ((j > 0 && grid[i][j - 1] == -1) || (j < n - 1 && grid[i][j + 1] == -1)) {
                        score += grid[i][j];
                    }
                }
            }
        }

        return score;
    }
};
