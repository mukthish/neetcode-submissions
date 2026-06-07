class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> mp = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        for (auto& c : s) {
            if (c == '(' or c == '{' or c == '[') {
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
