class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> count_s1(26);
        vector<int> count_s2(26);
        for (int i = 0; i < s1.size(); i++) {
            count_s1[s1[i]-'a']++;
            count_s2[s2[i]-'a']++;
        }

        int match = 0;
        for (int i = 0; i < 26; i++) {
            match += (count_s1[i] == count_s2[i]);
        }

        for (int r = s1.size(); r < s2.size(); r++) {
            if (match == 26) {
                return true;
            }
            int l = r - s1.size();
            int left = s2[l]-'a', right = s2[r]-'a';
            if (count_s1[left] == count_s2[left]) {
                match--;
            }
            count_s2[left]--;
            if (count_s1[left] == count_s2[left]) {
                match++;
            }
            if (count_s1[right] == count_s2[right]) {
                match--;
            }
            count_s2[right]++;
            if (count_s1[right] == count_s2[right]) {
                match++;
            }
        }
        return match == 26;
    }
};
