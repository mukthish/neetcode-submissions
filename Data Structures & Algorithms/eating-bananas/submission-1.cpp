class Solution {
    bool can_eat(vector<int>& piles, int h, int rate) {
        long long time = 0;
        for (auto& p : piles) {
            time += ((p-1) / rate) + 1;
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int m = l + (r - l) / 2;
            if (can_eat(piles, h, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
