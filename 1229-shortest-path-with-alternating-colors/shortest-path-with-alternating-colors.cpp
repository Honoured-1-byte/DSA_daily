class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> adj(2, vector<vector<int>>(n));        
        for (const auto& edge : redEdges) adj[0][edge[0]].push_back(edge[1]); 
        for (const auto& edge : blueEdges) adj[1][edge[0]].push_back(edge[1]); 
        vector<vector<int>> dist(n, vector<int>(2, -1));        
        queue<pair<int, int>> q;
        dist[0][0] = 0;
        dist[0][1] = 0;
        q.push({0, 0}); 
        q.push({0, 1}); 
        while (!q.empty()) {
            auto [currNode, currColor] = q.front();
            q.pop();
            int nextColor = 1 - currColor;
            for (int neighbor : adj[nextColor][currNode]) {
                if (dist[neighbor][nextColor] == -1) {
                    dist[neighbor][nextColor] = dist[currNode][currColor] + 1;
                    q.push({neighbor, nextColor});
                }
            }
        }
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            int d0 = dist[i][0];
            int d1 = dist[i][1];            
            if (d0 == -1 && d1 == -1) answer[i] = -1;
            else if (d0 == -1) answer[i] = d1;
            else if (d1 == -1) answer[i] = d0;
            else answer[i] = min(d0, d1);
        }
        return answer;
    }
};