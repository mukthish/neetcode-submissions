class TimeMap {
    unordered_map<string, vector<pair<int, string>>> time_store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& t = time_store[key];
        int l = 0, r = t.size() - 1;
        string result = "";
        while (l <= r) {
            int m = l + (r - l) / 2;
            int tm = t[m].first;
            if (tm > timestamp) {
                r = m - 1;
            } else {
                result = t[m].second;
                l = m + 1;
            }
        }
        return result;
    }
};
