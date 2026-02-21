class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            int bits = 0;
            for (int n = i; n; n >>= 1)
                bits += n & 1;
            cnt += primes.count(bits);
        }
        return cnt;
    }
};
