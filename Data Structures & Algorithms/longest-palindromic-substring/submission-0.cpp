class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            // odd length
            int l = i, r = i;
            while (l >= 0 and r < n and s[l] == s[r]) {
                if (r - l > y - x) {
                    y = r;
                    x = l;
                }
                l--;
                r++;
            }
            // even length
            l = i, r = i + 1;
            while (l >= 0 and r < n and s[l] == s[r]) {
                if (r - l > y - x) {
                    y = r;
                    x = l;
                }
                l--;
                r++;
            }
        }
        return string(s.begin() + x, s.begin() + y + 1);
    }
};
