class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";
        for (auto& s : strs) {
            code += to_string(s.size()) + '#' + s;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> original;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(string(s.begin() + i, s.begin() + j));
            original.emplace_back(string(s.begin() + j + 1, s.begin() + j + 1 + len));
            i = j + 1 + len;
        }
        return original;
    }
};
