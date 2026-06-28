class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        int maxf = 0;
        int maxCount = 0;
        for (char& t : tasks) {
            count[t - 'A']++;
            if (maxf == count[t - 'A']) {
                maxCount++;
            } else if (maxf < count[t - 'A']) {
                maxf = count[t - 'A'];
                maxCount = 1;
            }
        }

        int parts = maxf - 1;
        int partLen = n - (maxCount - 1);
        int emptySlots = parts * partLen;
        int availableTasks = tasks.size() - maxf * maxCount;
        int idles = max(0, emptySlots - availableTasks);
        return tasks.size() + idles;
    }
};
