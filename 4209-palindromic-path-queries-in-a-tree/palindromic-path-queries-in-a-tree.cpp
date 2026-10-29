class Solution {
    int timer;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<int> bit;
    int n;

    void dfs(int u, int p, int d, const vector<vector<int>>& adj) {
        tin[u] = ++timer;
        up[u][0] = p;
        for (int i = 1; i < 16; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        depth[u] = d;
        
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, adj);
            }
        }
        tout[u] = timer;
    }

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] ^= val;
        }
    }

    void range_update(int l, int r, int val) {
        add(l, val);
        add(r + 1, val);
    }

    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res ^= bit[idx];
        }
        return res;
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < 16; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        
        for (int i = 15; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n, vector<int>(16, 0));
        bit.assign(n + 2, 0);
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dfs(0, 0, 0, adj);
        for (int i = 0; i < n; i++) {
            range_update(tin[i], tout[i], 1 << (s[i] - 'a'));
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (const string& q : queries) {
            if (q[0] == 'u') {
                int u = 0;
                int idx = 7; 
                while (q[idx] != ' ') {
                    u = u * 10 + (q[idx] - '0');
                    idx++;
                }
                char c = q.back();

                int old_mask = 1 << (s[u] - 'a');
                int new_mask = 1 << (c - 'a');
                int diff = old_mask ^ new_mask;
                range_update(tin[u], tout[u], diff);
                s[u] = c;
            } else {
                int u = 0, v = 0;
                int idx = 6; 
                while (q[idx] != ' ') {
                    u = u * 10 + (q[idx] - '0');
                    idx++;
                }
                idx++;
                while (idx < q.size()) {
                    v = v * 10 + (q[idx] - '0');
                    idx++;
                }

                int lca = get_lca(u, v);
                int mask_u = query(tin[u]);
                int mask_v = query(tin[v]);
                int path_mask = mask_u ^ mask_v ^ (1 << (s[lca] - 'a'));
                ans.push_back((path_mask & (path_mask - 1)) == 0);
            }
        }

        return ans;
    }
};