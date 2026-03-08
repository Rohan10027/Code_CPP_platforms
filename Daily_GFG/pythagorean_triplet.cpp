class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> squares;

        // Insert squares of all elements
        for (int i = 0; i < n; i++) {
            squares.insert(arr[i] * arr[i]);
        }

        // Check all pairs
        for (int i = 0; i < n; i++) {
            int x = arr[i];
            for (int j = i + 1; j < n; j++) {
                int y = arr[j];
                int sum = x * x + y * y;
                if (squares.count(sum)) {
                    return true;
                }
            }
        }

        return false;
    }
};
