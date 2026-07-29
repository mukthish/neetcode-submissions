class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) {
            return n;
        }
        vector<int> stairs = {1, 2};
        for (int i = 3; i <= n; i++) {
            swap (stairs[0], stairs[1]);
            stairs[1] += stairs[0];
        }
        return stairs[1];
    }
};
