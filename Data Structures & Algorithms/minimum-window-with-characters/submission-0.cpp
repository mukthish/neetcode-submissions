class Solution {
    bool check(unordered_map<char, int>& cs, unordered_map<char, int>& ct) {
        for (auto& [k,v] : ct) {
            if (ct[k] > cs[k]) {
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        unordered_map<char, int> ct, cs;
        for (int i = 0; i < t.size(); i++) {
            ct[t[i]]++;
        }
        int l = 0, r = 0;
        int min_len = INT_MAX;
        string res="";
        while (r < s.size()) {
            cs[s[r]]++;
            while (l <= r and check(cs, ct)) {
                if (r-l+1 < min_len) {
                    min_len = r-l+1;
                    res = string(s.begin()+l, s.begin()+r+1);
                }
                cs[s[l]]--;
                l++;
            }
            r++;
        }
        return res;
    }
};
