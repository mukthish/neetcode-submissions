class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_map<char, int> mp;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            while (mp[s[i]] > 1) {
                mp[s[l]]--;
                l++;
            }
            max_len = max(max_len, i-l+1);
        }
        return max_len;
    }
};
