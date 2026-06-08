class MinStack {
public:
    stack<pair<int, int>> st;
    
    MinStack() {
    }
    
    void push(int val) {
        if (!st.empty() and st.top().second < val) {
            st.push({val, st.top().second});
        } else {
            st.push({val, val});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
