class Solution {
public:
    int smallestNumber(int n) {
        return (1<<(32-countl_zero((unsigned)n)))-1;
    }
};
