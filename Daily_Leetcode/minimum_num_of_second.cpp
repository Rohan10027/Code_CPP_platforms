class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        // Helper function to check if the mountain can be reduced to zero within maxTime.
        auto canCompleteWork = [&](long long maxTime) -> bool {
            long long totalWork = 0;
            for (int workerTime : workerTimes) {
                // Compute how much work this worker can do in maxTime
                long long lo = 0, hi = mountainHeight;
                while (lo < hi) {
                    long long mid = (lo + hi + 1) / 2;
                    long long workTime = workerTime * mid * (mid + 1) / 2;
                    if (workTime <= maxTime)
                        lo = mid;
                    else
                        hi = mid - 1;
                }
                totalWork += lo;
                if (totalWork >= mountainHeight) return true;
            }
            return totalWork >= mountainHeight;
        };
        
        // Binary search for the minimum time to reduce the mountain height to zero
        long long lo = 0, hi = 1LL * *max_element(workerTimes.begin(), workerTimes.end()) * mountainHeight * (mountainHeight + 1) / 2;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (canCompleteWork(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        
        return lo;
    }
};
