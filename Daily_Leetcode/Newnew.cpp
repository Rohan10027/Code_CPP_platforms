class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        st.push(-1);

        vector<int> prevSmaller(n), nextSmaller(n);

        for (int i = 0; i < n; i++) {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
                st.pop();
            prevSmaller[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();
        st.push(-1);

        for (int i = n - 1; i >= 0; i--) {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
                st.pop();
            nextSmaller[i] = (st.top() == -1) ? n : st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int width = nextSmaller[i] - prevSmaller[i] - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> histogram(cols, 0);
        int answer = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    histogram[j]++;
                else
                    histogram[j] = 0;
            }
            answer = max(answer, largestRectangleArea(histogram));
        }

        return answer;
    }
};
