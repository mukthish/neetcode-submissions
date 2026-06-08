class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& t : tokens) {
            if (t == "+" or t == "-" or t == "*" or t == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c;
                if (t == "+") {
                    c = b + a;
                } else if (t == "-") {
                    c = b - a;
                } else if (t == "*") {
                    c = b * a;
                } else {
                    c = b / a;
                }
                st.push(c);
            } else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
