class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        pair<int, int> curr = {intervals[0][0], intervals[0][1]};
        int count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < curr.second) {
                count++;
                if (intervals[i][1] < curr.second) {
                    curr = {intervals[i][0], intervals[i][1]};
                }
            } else {
                curr = {intervals[i][0], intervals[i][1]};
            }
        }
        return count;
    }
};
