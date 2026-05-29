class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_len = 0;
        for (auto& s : st) {
            if (st.count(s-1))
                continue;
            int len = 0;
            int t = s;
            while (st.count(t)) {
                t++;
                len++;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
