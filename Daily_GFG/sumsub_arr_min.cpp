class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int n = arr.size();
        
        stack<int> st;
        st.push(-1); // sentinel

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && arr[i] < arr[st.top()]) {
                int mid = st.top();
                st.pop();

                int left = mid - st.top();
                int right = i - mid;

                ans = (ans + 1LL * arr[mid] * left * right) % MOD;
            }
            st.push(i);
        }

        while (st.top() != -1) {
            int mid = st.top();
            st.pop();

            int left = mid - st.top();
            int right = n - mid;

            ans = (ans + 1LL * arr[mid] * left * right) % MOD;
        }

        return ans;
    }
};
