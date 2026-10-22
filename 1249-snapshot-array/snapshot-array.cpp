class SnapshotArray {
    int cur_snap = 0;
    vector<vector<pair<int, int>>> history;
public:
    SnapshotArray(int length) {
        history.resize(length);
        for (int i = 0; i < length; i++) history[i].push_back({0, 0}); 
    }    
    void set(int index, int val) {
        if (!history[index].empty() && history[index].back().first == cur_snap) history[index].back().second = val;
        else history[index].push_back({cur_snap, val});
    }    
    int snap() {
        return cur_snap++;
    }    
    int get(int index, int snap_id) {
        const auto& records = history[index];
        int lo = 0, hi = records.size() - 1, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (records[mid].first <= snap_id) {
                ans = records[mid].second;
                lo = mid + 1; 
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */