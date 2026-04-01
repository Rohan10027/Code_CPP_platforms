class Solution {
  public:
    int countStrings(int n) {
        long long endWith0 = 1;
        long long endWith1 = 1;
        
        for (int i = 2; i <= n; i++) {
            long long newEndWith0 = endWith0 + endWith1;
            long long newEndWith1 = endWith0;
            
            endWith0 = newEndWith0;
            endWith1 = newEndWith1;
        }
        
        return endWith0 + endWith1;
    }
};
