class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        for (auto& c : s) {
            if (mp.count(c)) {
                st.push(mp[c]);
            } else {
                if (st.empty() or st.top() != c) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
