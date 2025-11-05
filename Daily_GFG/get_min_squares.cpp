class Solution {
  public:
    bool isSquare(int n) {
        int s = sqrt(n);
        return s * s == n;
    }

    // Check if n = a² + b²
    bool isSumOfTwoSquares(int n) {
        for (int i = 1; i * i <= n; ++i) {
            if (isSquare(n - i * i)) return true;
        }
        return false;
    }

    // Reduce n by dividing out 4^k
    void reduce(int& n) {
        while (n % 4 == 0) n /= 4;
    }

    int minSquares(int n) {
        // Case 1: n is a perfect square
        if (isSquare(n)) return 1;

        // Case 2: n = a² + b²
        if (isSumOfTwoSquares(n)) return 2;

        // Case 3: Check if n = 4^k (8m + 7) → needs 4
        int temp = n;
        reduce(temp);
        if (temp % 8 == 7) return 4;

        // Otherwise, must be 3
        return 3;
    }
};
