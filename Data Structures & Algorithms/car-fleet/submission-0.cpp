class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> car(n);
        for (int i = 0; i < n; i++) {
            car[i] = {position[i], speed[i]};
        }
        sort(car.rbegin(), car.rend());
        stack<float> st;
        for (int i = 0; i < n; i++) {
            if (!st.empty() and st.top() >= (float)(target - car[i].first) / car[i].second) {
                continue;
            }
            st.push(((float)(target - car[i].first) / car[i].second));
        }
        return st.size();
    }
};
