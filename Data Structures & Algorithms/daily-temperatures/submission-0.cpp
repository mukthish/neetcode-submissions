class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() and st.top().first < temperatures[i]) {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        while (!st.empty()) {
            res[st.top().second] = 0;
            st.pop();
        }
        return res;
    }
};
