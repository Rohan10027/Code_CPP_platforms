#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> frequency;
        vector<int> result;

        // Count the frequency of each number
        for (int num : nums) {
            frequency[num]++;
        }

        // Find the numbers that appear more than once
        for (auto& entry : frequency) {
            if (entry.second > 1) {
                result.push_back(entry.first);
            }
        }

        return result;
    }
};

