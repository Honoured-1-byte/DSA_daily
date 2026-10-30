class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string s, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        pq.push({0, 0, 1});
        dist[0][1] = 0;
        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();
            if (d > dist[u][count])
                continue;
            for (auto [v, w] : adj[u]) {
                if (s[u] == s[v]) {
                    if (count + 1 > k)
                        continue;
                    if (d + w < dist[v][count+1]) {
                        dist[v][count + 1] = d + w;
                        pq.push({d + w, v, count + 1});
                    }
                } else {
                    if (d + w < dist[v][1]) {
                        dist[v][1] = d + w;
                        pq.push({d + w, v, 1});
                    }
                }
            }
        }
        int ans = 1e9;
        for (int i = 1; i <= k; i++) {
            ans = min(ans, dist[n - 1][i]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};