class Solution {
   public:
    int numDecodings(string s) {
        int n = s.size();
        int dp1 = 1, dp2 = 0;
        for (int i = n - 1; i >= 0; i--) {
            int curr;
            if (s[i] == '0') {
                curr = 0;
            } else {
                curr = dp1;
                if (i + 1 < n and (s[i] == '1' or s[i] == '2' and s[i + 1] <= '6')) {
                    curr += dp2;
                }
            }
            dp2 = dp1;
            dp1 = curr;
        }
        return dp1;
    }
};
