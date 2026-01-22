// C-array version
class Solution {
public:
    // check if nums is non-decreasing ignoring INT_MAX
    static bool isNonDec(int* nums, int n) {
        int prev=INT_MIN;
        for (int i=0; i<n; i++) {
            while (i<n && nums[i]==INT_MAX) i++;
            if (i==n) break;
            if (nums[i]<prev) return 0;
            prev=nums[i];
        }
        return 1;
    }

    static int minimumPairRemoval(vector<int>& _nums) {
        const int n=_nums.size();
        int* nums=_nums.data();// just consider the C-array
        int op=0;

        while (!isNonDec(nums, n)) {
            int minPair=INT_MAX, s=-1, t=-1;
            // Find pair with minimum sum where both values are not INT_MAX
            for (int i=0; i<n-1; i++) {
                if (nums[i]==INT_MAX) continue;
                // Find next valid j > i
                int j=i+1;
                while (j<n && nums[j]==INT_MAX) j++;

                if (j<n && nums[j]!=INT_MAX) {
                    int pairSum=nums[i]+nums[j];
                    if (pairSum<minPair) {
                        minPair=pairSum;
                        s=i;
                        t=j;
                    }
                }
            }

            // Merge t into s, mark t as removed
            if (s!=-1 && t!=-1) {
                nums[s]+=nums[t];
                nums[t]=INT_MAX;
                op++;
            } 
            else 
                break; // no valid pair found
        }

        return op;
    }
};

