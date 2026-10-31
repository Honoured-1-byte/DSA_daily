class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        vector<int> odd_nodes;
        for (int i = 1; i <= n; i++)
            if (adj[i].size() & 1)
                odd_nodes.push_back(i);
        if (odd_nodes.size() == 0)
            return true;
        if (odd_nodes.size() == 2) {
            int u = odd_nodes[0];
            int v = odd_nodes[1];
            if (!adj[u].count(v))
                return true;
            for (int i = 1; i <= n; i++)
                if (i != u && i != v && !adj[u].count(i) && !adj[v].count(i))
                    return true;
            return false;
        }
        if (odd_nodes.size() == 4) {
            int a = odd_nodes[0];
            int b = odd_nodes[1];
            int c = odd_nodes[2];
            int d = odd_nodes[3];
            if (!adj[a].count(b) && !adj[c].count(d))
                return true;
            if (!adj[a].count(c) && !adj[b].count(d))
                return true;
            if (!adj[a].count(d) && !adj[b].count(c))
                return true;
            return false;
        }
        return 0;
    }
};