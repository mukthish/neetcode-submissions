class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            // odd length
            int l = i, r = i;
            while (l >= 0 and r < n and s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
            // even length
            l = i, r = i + 1;
            while (l >= 0 and r < n and s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};
