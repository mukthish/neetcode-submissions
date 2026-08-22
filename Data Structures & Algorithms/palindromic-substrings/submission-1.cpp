class Solution {
    int countPali(string s, int l, int r) {
        int count = 0;
        for (int i = 0; l - i >= 0 and r + i < s.size(); i++) {
            if (s[l - i] == s[r + i]) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count += countPali(s, i, i); // odd
            count += countPali(s, i, i + 1); // even
        }
        return count;
    }
};
