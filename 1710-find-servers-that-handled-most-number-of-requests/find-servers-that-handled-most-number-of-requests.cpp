class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> initial_free(k);
        iota(initial_free.begin(), initial_free.end(), 0); 
        priority_queue<int, vector<int>, greater<int>> free(greater<int>(), std::move(initial_free));        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> taken;
        vector<int> req(k, 0);
        int n = arrival.size();
        
        for (int i = 0; i < n; i++) {
            int t = arrival[i];
            int pref = i % k; 
            
            while (!taken.empty() && taken.top().first <= t) {
                int server_id = taken.top().second; 
                taken.pop();
                free.push(i + (server_id - pref + k) % k);
            }
            
            if (free.empty()) continue;
            
            int s = free.top();
            free.pop();
            int server_id = s % k;
            
            taken.emplace(t + load[i], server_id);
            req[server_id]++;
        }
        
        int maxi = 0;
        vector<int> ans;
        
        for (int i = 0; i < k; i++) {
            if (req[i] < maxi) continue;
            if (req[i] > maxi) {
                maxi = req[i];
                ans.clear(); 
            }
            ans.push_back(i);
        }
        
        return ans;
    }
};