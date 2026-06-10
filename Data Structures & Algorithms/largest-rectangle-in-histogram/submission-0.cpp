class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left_min(n, -1), right_min(n, n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() and heights[st.top()] > heights[i]) {
                right_min[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and heights[st.top()] > heights[i]) {
                left_min[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (right_min[i] - left_min[i] - 1));
        }
        return res;
    }
};
