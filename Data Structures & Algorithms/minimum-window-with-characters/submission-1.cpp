class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        unordered_map<char, int> ct, cs;
        for (int i = 0; i < t.size(); i++) {
            ct[t[i]]++;
        }
        int need = ct.size();
        int l = 0, r = 0;
        int min_len = INT_MAX;
        string res="";
        int have = 0;
        for (int r = 0; r < s.size(); r++) {
            cs[s[r]]++;
            if (cs[s[r]] == ct[s[r]]) {
                have++;
            }
            while (have == need) {
                if (r-l+1 < min_len) {
                    min_len = r-l+1;
                    res = string(s.begin()+l, s.begin()+r+1);
                }
                cs[s[l]]--;
                if (cs[s[l]] < ct[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return res;
    }
};
