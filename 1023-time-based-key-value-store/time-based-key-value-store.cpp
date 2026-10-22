class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {}    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";
        const auto& arr = it->second;
        int lo = 0, hi = arr.size() - 1;
        string ans = "";
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid].first <= timestamp) {
                ans = arr[mid].second; 
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */