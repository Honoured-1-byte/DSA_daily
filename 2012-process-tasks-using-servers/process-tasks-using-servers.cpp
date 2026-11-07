class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> inUse;
        int n = servers.size();
        for (int i = 0; i < n; i++) free_servers.push({servers[i], i});
        int m = tasks.size();
        vector<int> ans(m);
        long long current_time = 0;
        for (int i = 0; i < m; i++) {
            current_time = max(current_time, (long long)i);
            if (free_servers.empty() && !inUse.empty()) {
                current_time = max(current_time, get<0>(inUse.top()));
            }
            while (!inUse.empty() && get<0>(inUse.top()) <= current_time) {
                auto [release_time, weight, idx] = inUse.top();
                inUse.pop();
                free_servers.push({weight, idx});
            }
            auto [weight, idx] = free_servers.top();
            free_servers.pop();
            ans[i] = idx;
            inUse.push({current_time + tasks[i], weight, idx});
        }
        return ans;
    }
};