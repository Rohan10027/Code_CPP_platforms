class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0, last = INT_MIN; i < nums.size(); ++i){
        int mn = nums[i] - k;
        int mx = nums[i] + k;
        if(last < mn ) { last = mn; ans++; }
        else if(last < mx){ last = last + 1; ans++; }
    }
    return ans;
}
};
