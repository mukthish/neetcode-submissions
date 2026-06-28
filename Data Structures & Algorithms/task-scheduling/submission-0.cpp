class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for (auto& t : tasks) {
            count[t - 'A']++;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i]) {
                pq.push({count[i], i});
            }
        }    
        vector<int> cooldown(26);
        int res = 0;
        while (!pq.empty()) {
            vector<pair<int, int>> temp;
            auto [x, y] = pq.top();
            while (cooldown[y]) {
                temp.push_back(pq.top());
                pq.pop();
                if (pq.empty()) {
                    break;
                } else {
                    tie(x, y) = pq.top();
                }
            }
            for (int i = 0; i < 26; i++) {
                if (cooldown[i]) {
                    cooldown[i]--;
                }
            }
            if (!pq.empty()) {
                cooldown[y] = n;
                pq.pop();
                if (x > 1) {
                    pq.push({x-1, y});
                }
            }
            for (auto& t : temp) {
                pq.push(t);
            }
            res++;
        }
        return res;
    }
};
