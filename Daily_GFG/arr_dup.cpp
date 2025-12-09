class Solution {
  public:
    vector<int> findDuplicates(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int num = arr[i] % (n + 1);
            arr[num - 1] += n + 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int num = i + 1;
            int freq = (arr[i]) / (n + 1);
            if (freq == 2)
                ans.push_back(num);
        }
        return ans;
    }
};
