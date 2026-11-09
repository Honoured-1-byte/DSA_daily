class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Min-heap tracking free servers by their relative circular virtual coordinate
        priority_queue<int, vector<int>, greater<int>> free;
        
        // Min-heap tracking busy servers: {finish_time, virtual_server_id}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> taken;
        
        vector<int> req(k, 0);
        
        // Initially, all servers 0 through k - 1 are free
        for (int i = 0; i < k; i++) {
            free.push(i);
        }
        
        int n = load.size();
        for (int i = 0; i < n; i++) {
            int t = arrival[i];
            
            // Step 1: Release all servers that have finished before or at arrival time t
            while (!taken.empty() && taken.top().first <= t) {
                int x = taken.top().second;
                taken.pop();
                
                // Map the server into a virtual coordinate >= i based on its circular distance
                free.push(i + (k - (i % k) + (x % k)) % k);
            }
            
            // Step 2: If no servers are available, the request is dropped
            if (free.empty()) {
                continue;
            }
            
            // Step 3: Greedily pick the server with the smallest virtual coordinate
            int s = free.top();
            free.pop();
            
            // Mark the server as occupied until arrival[i] + load[i]
            taken.push({arrival[i] + load[i], s});
            req[s % k]++;
        }
        
        // Step 4: Identify the busiest servers
        int maxi = INT_MIN;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (req[i] < maxi) continue;
            if (req[i] > maxi) {
                maxi = req[i];
                ans = {};
            }
            ans.push_back(i);
        }
        
        return ans;
    }
};